#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int> &arr, int target){
  int n =  arr.size();
  int start = 0;
  int last = n-1;


  while(start<=last){
    int midPoint = start + ((last - start)/2);
    if(arr[midPoint]==target) return midPoint;
    else if (arr[midPoint]< target){
      start = midPoint + 1;
    }
    else{
      last = midPoint - 1;
    }
  }
  return -1;

}

int binarysearchRecursion(vector<int> &arr, int target, int start, int last){
  if(start>last) return -1;

  int midPoint = start + ((last - start)/2);

  if(arr[midPoint]==target) return midPoint;

  else if (arr[midPoint]<target){
    return binarysearchRecursion(arr, target, midPoint+1, last);
  }

  else{
    return binarysearchRecursion(arr, target, start, midPoint-1);
    }

}

int firstOccurence(vector<int> &arr, int target){
  int n =  arr.size();
  int start = 0;
  int last = n-1;
  int result = -1;

  while(start<=last){
    int midPoint = start + ((last - start)/2);
    if(arr[midPoint]==target){
      result = midPoint;
      last = midPoint-1;
    }
    else if(arr[midPoint]<target){
      start = midPoint + 1;
    }
    else
      last = midPoint - 1;
  }
  return result;
}

int squareRoot(int x){
  int start = 1; int last = x;
  int result = -1;

  while(start<=last){
    int midPoint = start + ((last - start)/2);
    if(midPoint * midPoint <= x){
      result = midPoint;
      start = midPoint + 1;
    }
    else{
      last = midPoint - 1;
    }
  }
  return result;
}

int lowerBond(vector<int> &arr, int target){
  int n = arr.size();
  int start = 0;
  int last = n-1;
  int ans = -1;

  while(start <= last){
    int midPoint = start + ((last - start)/2);
    if(arr[midPoint] >= target){
      ans = midPoint;
      last = midPoint - 1;
    }
    else{
      start = midPoint + 1;
    }
  }
  return ans;
}

int upperBond(vector<int> &arr, int target){
  int n = arr.size();
  int start = 0;
  int last = n-1;
  int ans = -1;

  while(start <= last){
    int midPoint = start + ((last - start)/2);
    if(arr[midPoint] > target){
      ans = midPoint;
      last = midPoint - 1;
    }
    else{
      start = midPoint + 1;
    }
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;

  vector<int> arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int target;
  cin>> target;

  vector<int> res;
  int low = lowerBond(arr, target);
  if(arr[low] != target ){
    res.push_back(-1);
    res.push_back(-1);
  }
  else{
    int ub = upperBond(arr, target);
    res.push_back(low);
    res.push_back(ub-1);
  }

  // cout<<binarysearch(arr, target);
  // cout<<binarysearchRecursion(arr, target, 0, n-1);
  // cout<<firstOccurence(arr, target);
  // cout<<squareRoot(40)<<"\n";
  cout<<"{"<<res[0]<<" "<<res[1]<<"}"<<endl;

  return 0;
}
