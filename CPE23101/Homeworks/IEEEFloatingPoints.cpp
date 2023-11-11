#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

void changeIntegerToBinary(int integerPart, vector <char>& binaryReal){
    stack <int> remainders;
    while (integerPart > 1){
        remainders.push(integerPart%2);
        integerPart = integerPart/2;
    }
    remainders.push(integerPart);
    while(!remainders.empty()){
        binaryReal.push_back(remainders.top() + '0');
        // cout << remainders.top();
        remainders.pop();
    }
}

void changeDecimalToBinary(double decimalPart, vector <char>& binaryReal){
    queue <int> leading;
    while (1){
        if (decimalPart == 1.0 || decimalPart == 0.0 || leading.size() >= 53){
            // leading.push(1);
            break;
        }
        decimalPart = decimalPart * 2;
        leading.push(int(decimalPart));
        if (decimalPart > 1){
            decimalPart--;
        }
    }
    while (!leading.empty()){
        binaryReal.push_back(leading.front() + '0');
        leading.pop();
    }
}

void generateExponent(int powerBias, char* exponent){
    stack <int> remainders;
    while (powerBias > 1){
        remainders.push(powerBias%2);
        powerBias = powerBias/2;
    }
    remainders.push(powerBias);
    int binaryExponent = remainders.size();

    for (int i =0;i < 11-binaryExponent;i++){
        exponent[i] = '0';
    }
    int i;
    for (i = 11-binaryExponent ; !remainders.empty();i++){
        exponent[i] = remainders.top() + '0';
        remainders.pop();
    }
    i++;
    exponent[i] = '\0';
}

void generateMantissa (vector <char>& binaryReal, char* mantissa){
    int i;
    for (i =1;i<binaryReal.size() || i<53;i++){
        if (i >= binaryReal.size()){
            mantissa[i-1] = '0';
        }
        else{
            mantissa[i-1] = binaryReal[i];
        }
    }
    mantissa[i-1] = '\0';
}

int main(){
    double realNumber;
    vector <char> binaryReal;

    char sign;
    char exponent[12];
    char mantissa[53];

    cout << "Enter a real Number > ";
    cin >> realNumber;

    if (realNumber >= 0){
        sign = '0';
    }
    else{
        realNumber = realNumber * (-1.0);
        sign = '1';
    }

    int integerPart = (int)realNumber;
    cout << "\nInteger part is " << integerPart << '\n';
    changeIntegerToBinary(integerPart, binaryReal);
    // for (int i =0;i<binaryReal.size();i++){
    //     cout << binaryReal[i];
    // }
    int twoPower = binaryReal.size() - 1;
    // cout << " is 2 power to " << twoPower;
    // cout <<'\n';

    double decimalPart = realNumber - integerPart;
    cout << "Decimal part is " << decimalPart;
    // binaryReal.push_back('.');

    changeDecimalToBinary(decimalPart, binaryReal);
    // cout << "\nFull form of binary number is ";

    generateMantissa(binaryReal,mantissa);
    // for (int i =0;i<binaryReal.size();i++){
    //     cout << binaryReal[i];
    // }
    cout << "\n\n";

    int powerBias = 1023 + twoPower;
    generateExponent(powerBias,exponent);

    cout << "Sign : " << sign << "\n";
    cout << "Exponent : " << exponent << "\n";
    cout << "Mantissa : " << mantissa << "\n\n";
    cout << "========================== IEEE 754 Format ==========================\n\n";
    cout << sign << " " << exponent << " " << mantissa << "\n\n";
    cout << "=====================================================================\n";
    return 0;
}