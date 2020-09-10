#include<iostream>
using namespace std;
int main(){
	int num1[1000], num2[1000],res[100],i,j,n1,n2,k,temp=0,flag=0;
	cout<<"Enter size of num1 array"<<endl;
	cin >> n1;
	cout<<"Enter num1 array Elements"<<endl;
	for(i=0;i<n1;i++){
		cin >> num1[i];
	}
	cout<<"Enter size of num2 array"<<endl;
	cin >> n2;
	cout<<"Enter num2 array Elements"<<endl;
	for(i=0;i<n2;i++){
		cin >> num2[i];
	}
	for(i=0;i<n1;i++){
		flag=0;
		for(j=0;j<n2;j++){
			if(num1[i]==num2[j]){
				for(k=j+1;k<n2;k++){
					if(num2[k]>num1[i]){
						res[temp]=num2[k];
						++temp;
						flag=1;
						break;
					}
				}
				if(flag==0){
					res[temp]=-1;
					++temp;
				}
				break;
			}
		}
	}
	for(i=0;i<temp;i++){
		cout<<res[i]<<" ";
	}
}
