#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int profit,weight;
};
bool compare(Item a,Item b){
    return (double)a.profit/a.weight>(double)b.profit/b.weight;
}
double FactorialKnapsak(int w,vector<Item> &items){
    sort(items.begin(),items.end(),compare);
    double maxValue=0.0;
    for (Item item:items){
        if(w==0) break;
        if(item.weight<=w){
            maxValue+=item.profit;
            w-=item.weight;
        }
        else{
            maxValue+=(double)item.profit*w/item.weight;
            break;
        }
        
    }
    return maxValue;
}
int main()
{
    int w,n;
    cout<<"Enter capacity :";
    cin>>w;
    cout<<"Enter no of items :";
    cin>>n;
    vector<Item> items(n);
    for(int i=0;i<n;i++){
        cout<<"Enter profit and weight for item :"<<i+1<<":";
        cin>>items[i].profit>>items[i].weight;
    }
    double result=FactorialKnapsak(w,items);
    cout<<"Max val :"<<result<<endl;

    return 0;
}

/**
 capacity:50
 No of items :3 
 Enter profit and weight for item:60 10
                                  100 20
                                  120 30
                                  
 output:240
 
**/
