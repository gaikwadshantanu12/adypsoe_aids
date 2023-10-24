/*
Write a program in C++ to use map associative container.
The keys will be the names of states and the values will be the populations of the states.
When the program runs, the user is prompted to type the name of the state.
The program then loops in th emap, using the state name as an index and returns the population of the state.
*/

#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main() {
	typedef map<string,int> mapType;
	mapType populationMap;

	populationMap.insert(pair<string, float>("Maharashtra", 125));
	populationMap.insert(pair<string, float>("Uttar_Pradesh", 225));
	populationMap.insert(mapType::value_type("Bihar", 120));
	populationMap.insert(mapType::value_type("West Bengal", 100));
	populationMap.insert(make_pair("Madhya_Pradesh", 90));
	populationMap.insert(make_pair("Tamil_Nadu", 80));
	populationMap.insert(make_pair("Rajasthan", 78));
	populationMap.insert(make_pair("Andhra_Pradesh", 53));
	populationMap.insert(make_pair("Odisha", 47));
	populationMap.insert(make_pair("Kerala", 38));
	populationMap.insert(make_pair("Telangana", 37));
	populationMap.insert(make_pair("Assam", 35));
	populationMap.insert(make_pair("Jharkhand", 38));
	populationMap.insert(make_pair("Karnataka", 68));
	populationMap.insert(make_pair("Gujarat", 70));
	populationMap.insert(make_pair("Punjab", 31));
	populationMap.insert(make_pair("Chhattisgarh", 30));
	populationMap.insert(make_pair("Haryana", 29));
	populationMap.insert(make_pair("UT_Delhi", 19));
	populationMap.insert(make_pair("UT_Jammu_and_Kashmir", 14));
	populationMap.insert(make_pair("Uttarakhand", 12));
	populationMap.insert(make_pair("Himachal_Pradesh", 8));
	populationMap.insert(make_pair("Tripura", 04));
	populationMap.insert(make_pair("Meghalaya", 4));
	populationMap.insert(make_pair("Manipur", 3));
	populationMap.insert(make_pair("Nagaland", 2));
	populationMap.insert(make_pair("Goa", 2));
	populationMap.insert(make_pair("Arunachal_Pradesh", 2));
	populationMap.insert(make_pair("UT_Puducherry", 2));
	populationMap.insert(make_pair("Mizoram", 1));
	populationMap.insert(make_pair("UT_Chandigarh", 1));
	populationMap.insert(make_pair("Sikkim", 1));
	populationMap.insert(make_pair("UT_Dadra_and_Nagar_Haveli_and_Daman_and_Diu", 1));
	populationMap.insert(make_pair("UT_Andaman_and_Nicobar_Islands", 1));
	populationMap.insert(make_pair("UT_Lakshadweep", 0.0003));
	populationMap.insert(make_pair("UT_Ladakh", 0.00006));

	mapType::iterator iter = --populationMap.end();
	populationMap.erase(iter);

	cout << "Total state and UT of India with Size of populationMap: " << populationMap.size() << '\n';

	for (iter = populationMap.begin(); iter != populationMap.end(); ++iter) {
	 	cout << iter->first <<" : " << iter->second << " million\n";
	}

	char c;
	do {
		string state;
		cout<<"\nEnter that state you want to know the population of : ";
		cin>>state;
		iter = populationMap.find(state);
		if( iter != populationMap.end() )
		    cout << state <<"'s populations is " << iter->second << " million" << endl;
		else
		    cout << "State is not in Population Map\n";

		cout<<"Do you wish to continue?(y/n) : ";
		cin>>c;
	}while(c=='y'||c=='Y');

	populationMap.clear();
	return 0;
}
