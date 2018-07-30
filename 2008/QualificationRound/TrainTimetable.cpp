// Author: Abhimanyu Bishnoi
// Date: 29 July, 2018
// Average Time Complexity: O(n)
// For explanation refer to: https://codejam.withgoogle.com/codejam/contest/32013/dashboard#s=a&a=1

#include <bits/stdc++.h>

using namespace std;

struct Trip{
	int start;
	int end;
	int startSt; // A: 0 ; B: 1
};

bool compare_trips(const struct Trip& a, const struct Trip& b){
	return a.start < b.start;
}

int main(){
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		int turnAround;
		cin>>turnAround;
		int na,nb;
		cin>>na>>nb;
		vector <struct Trip> trips;
		for (int i = 0; i < na; ++i)
		{
			struct Trip trip;
			int hour,min;
			char temp;
			cin>>hour>>temp>>min;
			trip.start = hour*60 + min;
			
			cin>>hour>>temp>>min;
			trip.end = hour*60 + min;
			
			trip.startSt = 0;
			trips.push_back(trip);
		}

		for (int i = 0; i < nb; ++i)
		{
			struct Trip trip;
			int hour,min;
			char temp;
			cin>>hour>>temp>>min;
			trip.start = hour*60 + min;
			
			cin>>hour>>temp>>min;
			trip.end = hour*60 + min;
			
			trip.startSt = 1;
			trips.push_back(trip);
		}
		sort(trips.begin(), trips.end(), compare_trips);
		int count[2] = {0,0}; //Count of trains for both stations
		
		priority_queue <int, vector<int>, greater<int> > minHeapA,minHeapB; //Min heap to store train start time
		for (int i = 0; i < trips.size(); ++i)
		{
			int startTime = trips[i].start;
			int endTime = trips[i].end;
			int startSt = trips[i].startSt;
			if(startSt == 0){
				if(minHeapA.size()!=0 && minHeapA.top() <= startTime){
					//train available
					minHeapA.pop();
					minHeapB.push(endTime + turnAround);
				}else{
					//train not available
					count[0]++;
					minHeapB.push(endTime + turnAround);

				}
			}
			else{
				if(minHeapB.size()!=0 && minHeapB.top() <= startTime){
					//train available
					minHeapB.pop();
					minHeapA.push(endTime + turnAround);
				}else{
					//train not available
					count[1]++;
					minHeapA.push(endTime + turnAround);
					
				}
			}
		}
		cout<<"Case #"<<t<<": "<<count[0]<<" "<<count[1]<<"\n";
	}
	return 0;
}