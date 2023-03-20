#include <iostream>
#include <list>
using namespace std;
#include "PoliticalSys.h"

int main(int argc, char* argv[]) {
    string filename(argv[1]);
    PoliticalSys* politicalSys = new PoliticalSys(filename);
    int menuOption =9;
    while(menuOption!=0)
    {
        start:
        cout<< "1. Add Politician" << endl;
        cout<< "2. Add Party" << endl;
        cout<< "3. Remove Politician" << endl;
        cout<< "4. Remove Party" << endl;
        cout<< "5. Elections" << endl;
        cout<< "6. Print Politicians" << endl;
        cout<< "7. Print Parties" << endl;
        cout<< "8. Biggest Party" << endl;
        cout<< "0. Exit" << endl;
        cin >> menuOption;
        if ( !cin ) // in case of a bad input clean cin
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto start;
        }
        switch(menuOption){
            case 1:
                cout<<"---Create Politician---"<<endl;
                tryAgain1:
                try{
                    politicalSys->addPolitician();
                }
                catch(SysException &e){
                    cout<<e.what()<<endl;
                    delete &e;
                    goto tryAgain1;
                }
                catch (...) {
                    goto exit;
                }
                break;
            case 2:
                cout<<"---Create Party---"<<endl;
                tryAgain2:
                try{
                    politicalSys->addParty();
                }
                catch(SysException &e){
                    cout<<e.what()<<endl;
                    delete &e;
                    goto tryAgain2;
                }
                catch (...) {
                    goto exit;
                }
                break;
            case 3:
                cout<<"---Remove Politician---"<<endl;
            tryAgain3:
                try{
                    politicalSys->removePolitician();
                }
                catch(SysException &e){
                    cout<<e.what()<<endl;
                    delete &e;
                    goto tryAgain3;
                }
                catch (...) {
                    goto exit;
                }
                break;
            case 4:
                cout<<"---Remove Party---"<<endl;
            tryAgain4:
                try{
                    politicalSys->removeParty();
                }
                catch(SysException &e){
                    cout<<e.what()<<endl;
                    delete &e;
                    goto tryAgain4;
                }
                catch (...) {
                    goto exit;
                }
                break;
            case 5: // do elections
                politicalSys->elections();
                break;
            case 6: //Print Politicians
                politicalSys->printPoliticians();
                break;
            case 7: // Print Parties
                politicalSys->printParties();
                break;
            case 8: // print the Biggest Party
                politicalSys->BiggestParty();
                break;
            case 0:
            exit:
                menuOption = 0;
                delete politicalSys;
                break;
        }
    }

    return 0;
}