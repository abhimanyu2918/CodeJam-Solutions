// Author: Abhimanyu Bishnoi
// Date: 29 July, 2018
// Average Time Complexity: O(n)
// For explanation refer to: https://codejam.withgoogle.com/codejam/contest/32013/dashboard#s=a&a=0

#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	int Case=1;
	while(T--){	
		int n;
		cin>>n;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		for (int i = 0; i < n; ++i)
		{
			char name[100];
			cin.getline(name,100);
		}

		int q;
		cin>>q;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		
		//Hash Map for storing strings (query) in a particular segment
		map <string, int> hashMap;

		//Count of Segments i.e number of time we need to switch engines
		int count=0;
		
		for (int i = 0; i < q; ++i)
		{
			char name[100];
			cin.getline(name,100);
			if(hashMap.find(name) == hashMap.end()){
				//Query not found in HashMap
				if(hashMap.size()==n-1){
					//Clear the Hash Map for new Segment and update counter
					hashMap.clear();
					count++;
				}
				hashMap[name] = 0;
			}
			
		}
		cout<<"Case #"<<Case<<": "<<count<<"\n";
		Case++;
	}
	return 0;
}