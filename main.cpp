#include <iostream>
#include <vector>
//#include <algorithm>
#include <math.h>
#include <regex>
using namespace std;
int equalSumIndex(vector<int> nums){
    int n=nums.size();
    if(n==1) return 0;
    int sum=0;
    for(int i = 0 ; i < n;++i){
       sum+=nums[i];
    }
    int sum_left = 0;
    for(int i = 0 ; i < n;++i){
        if(sum_left == (sum-nums[i]-sum_left)) return i;
        sum_left+=nums[i];
    }
    return -1;
}
int buyCar(vector<int> nums,int length,int k ){
    sort(nums.begin(),nums.end());
    int key = 0;
    int sum = 0;
    while(sum <= k){
        sum+= nums[key];
        key++;
    }
    return key-1;
}

bool consecutiveOnes(vector<int>& nums){
    int fbeg = 0;
    int fend = 0;
    int n = nums.size();
    for(int i = 0 ; i < n;++i ){
        if(nums[i]==1){
            fbeg = i;
            break;
        }
    }
    for(int i = n-1 ; i >=0;--i ){
        if(nums[i]==1){
            fend = i;
            break;
        }
    }
    if(fbeg==fend) return true;
    while(fbeg <= fend){
        if(nums[fbeg]!=1) return false;
        else fbeg++;
    }
    return true;
}
//253001988
//221538651
long sumLessThanTarget(vector<int>& nums,int target){
    vector<int> valid;
    int n = nums.size();
    for(int i = 0; i < n;++i){
        if(nums[i]<=target){
            valid.push_back(nums[i]);
        }
    }
    int right = (int) valid.size()-1;
    int left = 0;
    for(int i = right; i>=0;--i){
        if(nums[i]+nums[left] < target){
            right = i ;
            break;
        }
    }
    //[1, 2, 3, 5, 6 ] , 7
    //right = 4
    long max1=0;
    for(int i = 0; i < right;++i){
        max1 = valid[i]+valid[right];
        if(valid[i+1]+valid[right] >= target) {
            left=i+1;
            break;
        }
    }
    //[1, 2, 3, 5, 6 ] , 7
    //right = 4
    //left = 1
    long max2=0;
    for(int i = left+1; i < right;++i){
        max2=valid[left]+valid[i];
        if(valid[left]+valid[i+1] >= target){
            break;
        }
    }
    long max = max1 > max2 ? max1 : max2;
    return max;
}
int shortestString(string s){
    long zero = count(s.begin(),s.end(),'0');
    long one = count(s.begin(),s.end(),'1');
    return abs(zero - one);
}
string removeCharRecursive(string str)
{
    if (str.length() == 0) {
        return "";
    }

    if (str[0] == ' ') {
        return removeCharRecursive(str.substr(1));
    }
    return str[0]
           + removeCharRecursive(str.substr(1));
}

void assign_func(string ins,int level){
    string id,value_func,func_name,argu;  // value_func = func_name + argu
    int num_comp = 0;
    int num_splay = 0;
    int count_point = 0;
    int index[2]={0,0};
    int index_par[40];
                    int j = 0;
                    for(int i=0;i<(int)ins.size();++i){
                        if(j==2) break;
                        if(ins[i]==' '){
                            index[j]=i;
                            j++;
                        }
                    }
            id = ins.substr(index[0]+1,index[1]-index[0]-1);
            value_func  = ins.substr(index[1]+1);
            int find_parless = value_func.find('(');
            func_name = value_func.substr(0,find_parless);
            argu = value_func.substr(find_parless);
            cout<<"Ins : "<<ins<<endl;
            cout<<"ID : "<<id<<endl;
            cout<<"Name func : "<<func_name<<endl;
            cout<<"Argu      : "<<argu<<endl;
            // Is contains func_name + level,num_comp,num_splay
                     // If true => if decode == "" Type else thoat;
                     // If false => Undeclared

            // If true het o tren
            // Check func_name decode
                    // If decode[0] == '(' && decode[1] == ')' [1] => if(decode.size !=1 ) throw type math;
                    // else , check so dau phay , if count point + 2 != decode.length => type
                            // if true --> check is value , is variable 
                                                            // if variable -> find -> return nullptr : Undeclered -> decode != ""->type  -> argu.type != decode[k];
            // CHeck xong thi lam x  
            

            // Luu index cho ( , )
            count_point = 0;
            for(int i = 0 ;i<(int) argu.length();++i){
                if(argu[i] == '(' ||argu[i] == ')' ||argu[i] == ','){
                    index_par[count_point] = i;
                    count_point++;
                }
            }
            cout<<"Index of par : [ ";
            for(int i = 0 ; i< count_point-1;++i){
                cout<<index_par[i]<<" ";
            }
            cout<<"]"<<endl;
            int k = 1;
            for(int i = 0 ; i< count_point-1;++i){
                string temp = argu.substr(index_par[i]+1,index_par[i+1]-1);
                cout<<"Argu "<<i<<" : "<<temp<< "--->"<<k<<" at index"  <<index_par[k]<<endl;
                ++k;
            }
        
}
int PrimeNumber(int n){
    int i ;
    for( i = 2 ; i <= n/2;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int PrimeNumberWhile(int n){
    int i = 2;
    while(i<=n/2){
        if(n%i==0){
            return 0;
        }
        i++;
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
  cout<<PrimeNumber(n)<<endl;
  cout<<PrimeNumberWhile(n);
}