//
// Created by sasha on 1/15/23.
//


#include "PoliticalSys.h"
void PoliticalSys::createPolitician(string& first_name,string& last_name,int id,int pow,char partyType, char politicianType){
    Politician* pol;
    if (pow<0||id<0) // check the id and the power
        throw wrongDetailsException();
    auto iter = _politicians.begin();
    while(iter!=_politicians.end()){
        if((*iter)->getID()== id){
            throw wrongIDException();
        }
        iter++;
    }
    if (partyType == 'D'){ // creates democratic politician based on their types
        if (politicianType == 'S')
            pol = (Politician*) new Democratic_Socialist(first_name,last_name,id,pow);
        else if(politicianType == 'L')
            pol = (Politician*) new Democratic_Leader(first_name,last_name,id,pow);
        else
            throw wrongDetailsException();
    }
    else if (partyType == 'R'){ //  creates republican politician based on their types
        if (politicianType == 'S')
            pol = (Politician*) new Republican_Socialist(first_name,last_name,id,pow);
        else if(politicianType == 'L')
            pol = (Politician*) new Republican_Leader(first_name,last_name,id,pow);
        else
            throw wrongDetailsException();
    }
    else
        throw wrongDetailsException();
    _politicians.push_back(pol); // insert the politician to the end of the list
    searchNiceParty(pol); // search a party for him
}

void PoliticalSys::createParty(string& partyName,char partyType){
    Party* par = nullptr;
    auto iter = _parties.begin();
    while(iter!=_parties.end()){
        if((*iter)->getName()== partyName){ // if the name already exists throw exception
            throw wrongNameException();
        }
        iter++;
    }
    if (partyType =='D') // creates the party based on the type
        par = (Party*)new Democrat_Party(partyName);
    else if (partyType == 'R')
        par = (Party*)new Republican_Party(partyName);
    else
        throw wrongDetailsException(); // if here got the wrong type
    _parties.push_back(par); // insert the party to the end of the parties list
    _sortedParties.push_back(par); // insert the party to the end of the sorted parties list
    addNewParty(par); // add politicians to the new party
    sortParties();
}

PoliticalSys::PoliticalSys(string& filename){
    // initiate the variables
    char politicianType,partyType;
    string fName,lName,line;
    int id,pow;
    ifstream politics;
    politics.open(filename); // open the file
    getline(politics, line); // this line is "politician:"
    getline(politics, line); // the first politician
    while (line !="Parties:\r"){
        stringstream s(line);
        // extract data from the line
        s >> fName;
        s >> lName;
        s >> id;
        s >> pow;
        s >> partyType;
        s >> politicianType;
        createPolitician(fName,lName,id,pow,partyType,politicianType); // create the politician
        getline(politics, line);
    }
    while (!politics.eof())
    {
        getline(politics, line);
        stringstream s(line);
        // extract data from the line
        s >>fName;
        s >> partyType;
        createParty(fName,partyType); // create the party
    }
    politics.close();
}

void PoliticalSys::addNewParty(Party* par){
    auto iter = _politicians.begin();
    while(iter!=_politicians.end()){
        if ((*iter)->getParty()==nullptr||(*iter)->getParty()->size()>par->size())
            (*iter)->addParty(par); // add the politician to the party
        iter++;
    }
}

void PoliticalSys::addPolitician(){
    // initiate the variables for the politician
    int id,power,check=0;
    char politicianType,partyType;
    string fName,lName,line;
    cout<<"First name:"<<endl;
    cin>>fName;
    cout<<"Last name:"<<endl;
    cin>>lName;
    cout<<"ID:"<<endl;
    cin>>id; // check if got string by mistake
    if ( !cin ) // in case of a bad input clean cin
    {
        check=1;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"Power:"<<endl;
    cin>>power;
    cout<<"Republican or Democratic person"<<endl;
    cin>> partyType;
    cout<< "Leader or Social"<<endl;
    cin>>politicianType;
    if(check ==1) // throw exception at the end
        throw wrongIDException();
    createPolitician(fName,lName,id,power,partyType,politicianType); // create the politician
    sortParties();
}

void PoliticalSys::addParty(){
    string pName;
    char type;
    cout<<"Name:"<<endl;
    cin>>pName;
    cout<<"Republican or Democratic party"<<endl;
    cin>>type;
    createParty(pName,type); // create the party
}

void PoliticalSys::removePolitician(){
    int id;
    cout<<"Enter the ID:"<<endl;
    cin>>id; // check if got string by mistake
    if ( !cin ) // in case of a bad input clean cin
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw wrongIDException();
    }
    auto iter = _politicians.begin();
    while(iter!=_politicians.end()){
        if ((*iter)->getID()==id){ // search the politician with the given id
            Party* par = ((*iter)->getParty());
            par->deleteMember(*iter); // delete from the party
            delete *iter; // delete the actual politician
            _politicians.erase(iter); // delete the iterator from the list
            sortParties();
            return;
        }
        iter++;
    }
    throw wrongIDException(); // if here then the politician with the given id is not in the system

}

void PoliticalSys::searchNiceParty(Politician* pol){
    if (_parties.empty())
        return;
    for (auto it=_parties.begin();it!=_parties.end();it++)
    {
        int thisSize = (*it)->size();
        if (pol->getParty()==nullptr||pol->getParty()->size()>thisSize){
            pol->addParty(*it);
        }
    }

}

void PoliticalSys::removeParty(){
    string name;
    cout<<"Enter party name:"<<endl;
    cin>>name;
    vector<Politician*>* lostPoliticians = nullptr;
    auto iter = _parties.begin();
    while(iter!=_parties.end()){
        if ((*iter)->getName()==name){
            (*iter)->Notify("None");
            lostPoliticians = (*iter)->getMembers(); // retrieve the party members
            for (auto it =_sortedParties.begin();it!=_sortedParties.end();it++){
                if (*it==*iter){ // first delete the pointer from the sorted parties
                    _sortedParties.erase(it);
                    break;
                }
            }
            Party* par= *iter;
            _parties.erase(iter); // delete from the parties list
            for (auto it= lostPoliticians->begin();it!=lostPoliticians->end();it++) {
                (*it)->addParty(nullptr); // add all the politicians to the new party
                searchNiceParty(*it);
            }
            delete par; // delete the actual party
            sortParties();
            return;
        }
        iter++;
    }
    throw wrongNameException(); // if here them the party with the given name is not in the system
}

void PoliticalSys::printPoliticians(){
    cout<<"----Politicians----"<<endl;
    for (auto iter = _politicians.begin();iter!=_politicians.end();iter++)
        (*iter)->print();
}
void PoliticalSys::printParties(){
    cout<<"----Parties----"<<endl;
    for (auto iter = _parties.begin();iter!=_parties.end();iter++)
        (*iter)->print();
}

void PoliticalSys::BiggestParty(){
    cout<<"----Biggest Party----"<<endl;
    Party* par= _sortedParties.back(); // the largest party is at the end of the list
    string name = (par)->getName();
    cout<<"["<<name<<","<<(par)->size()<<"]"<<endl;
}

void PoliticalSys::elections(){
    Party* par;
    string chairman;
    cout<<"----Primaries----"<<endl;
    for (auto it=_parties.begin();it!=_parties.end();it++){ // make primaries in each party and elect a new chairman for them
        par = (*it);
        par->primaries();
        if (par->getChairman()== nullptr)
            chairman="None";
        else
            chairman = par->getChairman()->getName();
        cout<<chairman<<" is the chairman of "<<par->getName()<<endl; // print the result
    }
    cout<<"----Elections----"<<endl;
    par =(*_parties.begin());
    for (auto it=_parties.begin();it!=_parties.end();it++){
        if ((**it)>*par)
            par =(*it);
        cout<<"Party: "<<(*it)->getName()<<",Power: "<<(*it)->strength()<<endl; // print the strength of each party
    }
    cout<<"----Elections Results----"<<endl;
    if (par->getChairman()== nullptr)
        chairman="None";
    else
        chairman = par->getChairman()->getName();
    cout<<par->getName()<<" party won the elections and "<<chairman<<" is the prime minister"<<endl; // print the winner
}

PoliticalSys::~PoliticalSys(){
    for (auto iter=_parties.begin();iter!=_parties.end();iter++)
        delete (*iter);
    _parties.clear();

    for (auto iter=_politicians.begin();iter!=_politicians.end();iter++)
        delete (*iter);
    _politicians.clear();


}