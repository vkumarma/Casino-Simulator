//Programmer: Vivek
//Project 2
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
void updateBalance(int &bal,int payoff,bool won,int betAmt) { // updateBalance function is used to keep updating the user's current balance after winning and losing.
    if (won) {
        bal = bal + payoff * betAmt;
    }
    else {
       bal = bal - betAmt;
    }
}


int bettingAmmount (int &userMoney){ // betting amount function used so that the betting amount is not an invalid input,a negative number and not more than the userMoney or current balance.
    double betAmt;

    cout << endl << "Enter Betting Amount: ";
    cin >> betAmt;
    while(cin.fail()){ // This code is used to stop invalid inputs.
        cin.clear();
        cin.ignore(128 , '\n');
        cout << "Input a valid Betting Amount:  " << endl;
        cin >> betAmt;
        
    }
    
    if (betAmt < 1) {
        cout << "\nBetting amount cannot be negative";
        return -1;
    }
    
    if (userMoney < 1){
        cout << "You need to have more money to bet!\n";
        return -1;
    }
    
    if (betAmt > userMoney) {
       cout << "\nBetting Amount cannot be more than current balance";
        return -1;
    }
    
    return betAmt;
}
                             
                             
void highLow (int &userMoney){
    int betAmt;// declaration.
    
    do {
       betAmt = bettingAmmount(userMoney);
    } while(betAmt < 0);
    char playAgain;// declaration.
    char highLow;// declaration.
  
    
    if (betAmt == -1) { // Betting amount cannot be negative.
        return;
    }
    
    do { // to play again yes or no.
        int randNum = rand() % 10 + 1; // do generate random numbers.
        int randNum2 = rand() % 10 + 1;
        do { // to stop any invalid input and to give the user another prompt.
            cout << "\nCurrent Balance: " << userMoney;
            cout << "\n\nYour Number is: " << randNum << endl;
            cout << "\nIs The Next Number High(H/h) or Low(L/l)?";
            cout << "\nEnter Input: ";
            cin >> highLow;
            while(cin.fail()){// This code is used to stop invalid inputs.
                cin.clear();
                cin.ignore(128 , '\n');
                cout << "Input a valid Character" << endl;
                cin >> highLow;
                
            }
            if (highLow != 'H' && highLow != 'h' && highLow != 'L' && highLow != 'l') { // press h or H for high or press L or l for low.
                cout << "\ninvalid input";
            }
        } while (highLow != 'H' && highLow != 'h' && highLow != 'L' && highLow != 'l');
        
        if ((highLow == 'H' || highLow == 'h') && randNum2 > randNum){
            cout << "\nYou Win";
            updateBalance(userMoney, 1, true, betAmt); // to call the updateBalance function and to update the userMoney or current user balance.
        }
        
        else if ((highLow == 'L' || highLow == 'l') && randNum2 < randNum){
            cout << "\nYou Win";
            updateBalance(userMoney, 1, true, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
        }
        
        else if ((highLow == 'H' || highLow == 'h') && randNum2 < randNum){
            cout << "\nYou Lose";
            updateBalance(userMoney, 1, false, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
        }
        
        else if ((highLow == 'l' || highLow == 'L') && randNum2 > randNum){
            cout << "\nYou Lose";
            updateBalance(userMoney, 1, false, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
        }
        
        else {
            cout << "\nNumbers are the same";
            cout << "\nYou lose";
           updateBalance(userMoney, 1, false, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
        }
         
        do{
            cout << "\n\nDo You Want To Play Again?";
            cin >> playAgain;
            while(cin.fail()){// This code is used to stop invalid inputs.
                cin.clear();
                cin.ignore(128 , '\n');
                cout << "Input a valid Character" << endl;
                cin >> playAgain;
                
            }
          
            if(playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N'){
                cout << "\nError: Invalid Input. Try Again";
            }
        } while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N');
    } while (playAgain == 'y' || playAgain == 'Y');
}
void play21(int &userMoney) {
    int betAmt;
   do {
      betAmt = bettingAmmount(userMoney);// to call betting amount function.
   } while(betAmt < 0);
    char hitStay;
    int compNum;

    if (betAmt == -1) {// Betting amount cannot be negative.
       return;
   }
    int Num1 = rand() % 10 + 1;// to generate random numbers.
    int Num2 = rand() % 10 + 1;// to generate random numbers.
   
    cout << "\nCurrent Balance: " << userMoney << endl;
    int sum = Num1 + Num2;
     
    while (sum < 21) {
        cout << "This is your sum:  " << sum << endl;
        do {
            cout << "\nDo you want to hit(H/h) or stay(S/s)?";
            cout << "\nEnter Input: ";
            cin >> hitStay;
            while(cin.fail()){// This code is used to stop invalid inputs.
                cin.clear();
                cin.ignore(128 , '\n');
                cout << "Input a valid Character" << endl;
                cin >> hitStay;
                
            }
            if (hitStay != 'H' && hitStay != 'h' && hitStay!= 'S' && hitStay != 's') {
                cout << "\ninvalid input";// press h or H for hit or press S or s for stay.
            }
        } while (hitStay != 'H' && hitStay != 'h' && hitStay  != 'S' && hitStay  != 's');
        if (hitStay == 'H' || hitStay == 'h'){
            int value = rand() % 10 + 1;
            sum = sum + value;
        }
    }
    if (sum > 21) {
        cout << "You Lose" << endl;
        updateBalance(userMoney, 2, false, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
        
        return;
        
    }
    

        compNum = rand() % 7 + 16;
    cout << "The number generated by computer is: " << compNum << endl;
    if (compNum > sum) {
        cout << "You Lose" << endl;
       updateBalance(userMoney, 2, false, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
    }
    else {
        cout << "You Win" << endl;
        updateBalance(userMoney, 2, true, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
    }
                
                
}
void craps(int &userMoney) {
    int betAmt;
    do {
         betAmt = bettingAmmount(userMoney);
      } while(betAmt < 0);
    int randNum1;int randNum2;int sum;
    char choice;
    if (betAmt == -1) {// Betting amount cannot be negative.
        return;
    }
    
    randNum1 = rand() % 6 + 1;// to generate random numbers.
    randNum2 = rand() % 6 + 1;// to generate random numbers.
    do {
    cout << "\nCurrent Balance: " << userMoney << endl;
    cout << "would you like to Pass(p/P) or no Pass(n/N)? ";
        cin >> choice;
        while(cin.fail()){// This code is used to stop invalid inputs.
            cin.clear();
            cin.ignore(128 , '\n');
            cout << "Input a valid Character" << endl;
            cin >> choice;
            
        }
         
        if (choice != 'P' && choice != 'p' && choice!= 'n' && choice != 'N') {
                cout << "\ninvalid input";// press P or p for pass or press N or n for no pass.
            }
        } while (choice != 'P' && choice != 'p' && choice   != 'n' && choice   != 'N');
        
        sum = randNum1 + randNum2;
        if (choice == 'p' || choice == 'P') { // pass
            if (sum == 2 || sum == 3 || sum == 12) {
                cout << "You rolled " << randNum1 << " and " << randNum2 << " which equals to: " << sum << endl;
                cout << "You Lose" << endl;
                updateBalance(userMoney, 1, false, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
                
            }
            else if (sum == 7 || sum == 11) {
                cout << "You rolled " << randNum1 << "and " << randNum2 << " which equals to: " << sum << endl;
                cout << "You Win" << endl;
                updateBalance(userMoney, 1, true, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
                
            }
            }
        else {
            do {
                randNum1 = rand() % 6 + 1;// to generate random numbers.
                randNum2 = rand() % 6 + 1;// to generate random numbers.
            } while (randNum1 + randNum2 != 7 && randNum1 + randNum2 != sum);
            if(randNum1 + randNum2 == 7) {
               cout << "You rolled " << randNum1 << " and " << randNum2 << " which equals to: " << sum << endl;
               cout << "You Lose" << endl;
               updateBalance(userMoney, 1, false, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
            }
            else if (randNum1 + randNum2 == sum) {
               cout << "You rolled " << randNum1 << " and " << randNum2 << " which equals to: " << sum << endl;
               cout << "You Win" << endl;
               updateBalance(userMoney, 1, true, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
                
            }
            }
        if(choice == 'N' || choice == 'n'){ // no pass
            if (sum == 2 || sum == 3 || sum == 12) {
            cout << "You rolled " << randNum1 << " and " << randNum2 << " which equals to: " << sum << endl;
            cout << "You Win" << endl;
            updateBalance(userMoney, 1, true, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
            }
            else if(sum == 7 || sum == 11) {
            cout << "You rolled " << randNum1 << " and " << randNum2 << " which equals to: " << sum << endl;
            cout << "You Lose" << endl;
            updateBalance(userMoney, 1, false, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
            }
            }
        else {
            do {
                randNum1 = rand() % 6 + 1;// to generate random numbers.
                randNum2 = rand() % 6 + 1;// to generate random numbers.
            } while (randNum1 + randNum2 != 7 && randNum1 + randNum2 != sum);
            if(randNum1 + randNum2 == 7) {
            cout << "You rolled " << randNum1 << " and " << randNum2 << " which equals to: " << sum << endl;
            cout << "You Win" << endl;
            updateBalance(userMoney, 1, true, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
            }
            else if (randNum1 + randNum2 == sum) {
            cout << "You rolled " << randNum1 << " and " << randNum2 << " which equals to: " << sum << endl;
            cout << "You Lose" << endl;
            updateBalance(userMoney, 1, false, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
            }
        
}
}
void slots(int &userMoney, bool random = false) { // for test case of slots.
    int betAmt;
    if(random) {
        betAmt = rand() % 50 + 1;// to generate random numbers.
    }
    else{
        do {
           betAmt = bettingAmmount(userMoney);
        } while(betAmt < 0);
    }
    int randNum;int randNum1;int randNum2;
    if (betAmt == -1) {// Betting amount cannot be negative.
        return;
    }
    randNum = rand() % 9 + 1;// to generate random numbers.
    randNum1 =  rand() % 9 + 1;// to generate random numbers.
    randNum2 =  rand() % 9 + 1;// to generate random numbers.
    if (randNum == randNum1 == randNum2) {
        cout << randNum << "  " << randNum1 << "  " << randNum2 << endl;
        cout << "You Hit the Jackpot" << endl;
        updateBalance(userMoney, 99, true, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
    }
    else if(randNum == randNum1 || randNum == randNum2 || randNum1 == randNum2) {
        cout << randNum << "  " << randNum1 << "  " << randNum2 << endl;
        cout << "You Win" << endl;
        updateBalance(userMoney, 9, true, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
    }
    else {
        cout << randNum << "  " << randNum1 << "  " << randNum2 << endl;
        cout << "You Lose" << endl;
        updateBalance(userMoney, 9,false, betAmt);// to call the updateBalance function and to update the userMoney or current user balance.
        
    }
    
    
    
}
void testcasedriver(int userMoney) { // for test cases.
    updateBalance(userMoney, 3, true, 10);
    updateBalance(userMoney, 3, false, 10);
    updateBalance(userMoney, 3, true, -10);
    int numTimes = 0;
    cout << "How many times do you want to test the slots? " << endl;
    cin >> numTimes;
    for(int i =0; i< numTimes; i++){
        slots(userMoney, true);
    }
}



int main() {
    srand((unsigned int) time (0));// to generate random numbers.
    int userInput;
    int userMoney;
    
    userMoney = rand() % 100  + 100;// to generate random numbers.
    cout << "***********WELCOME TO MY CASINO***********";
    
    do{ // to keep looping until user enters 6 for exit.
        do{ // to keeping looping until user enters valid option.
            cout << "\n\nCurrent Money: " << userMoney;
            cout << "\n1) Play High-Low";
            cout << "\n2) Play 21";
            cout << "\n3) Play Craps";
            cout << "\n4) Play the Slots";
            cout << "\n5) Run Test Case";
            cout << "\n6) Leave Casino";
            cout << "\nEnter an option: ";
            cin >> userInput;
            while(cin.fail()){// This code is used to stop invalid inputs.
                cin.clear();
                cin.ignore(128 , '\n');
                cout << "Input a valid option" << endl;
                cin >> userInput;
                
            }
            
            if(userInput < 0 || userInput > 6){
                cout << "\nERROR: Invalid Input";
            }
            
        } while (userInput < 0 || userInput > 6);
        
        
        if (userInput == 1){
            highLow(userMoney);// function calling.
        }
        
        else if (userInput == 2) {
            play21(userMoney);// function calling.
        }
        
        else if (userInput == 3) {
            craps(userMoney);// function calling.
        }
        
        else if (userInput == 4) {
            slots(userMoney);// function calling.
         }
        
        else if (userInput == 5) {
            testcasedriver(userMoney);// function calling.
        }
        
        else {
            
        }
    
    } while (userInput != 6);
    
    cout << "Thank You For Playing\n";
}

