#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream> 
using namespace std;
double epsilon= 1e-10;
class Point {
 public:
  double x;
  double y;

 public:
  Point()
      : x(0), y(0) {}  // Default constructor initializing coordinates to (0,0)
  Point(double xVal, double yVal)
      : x(xVal), y(yVal) {}  // Parameterized constructor

  double X() const { return x; }  // Accessor for x coordinate
  double Y() const { return y; }  // Accessor for y coordinate

};

double slope(pair<Point,Point>&a){ return (a.second.y - a.first.y) / (a.second.x - a.first.x); }
double intercept(pair<Point,Point>&a,double s){return (a.first.y - s*a.first.x);}
double find_val(pair<Point,Point>&a,double x_val){ return slope(a)*(x_val - a.first.x) + a.first.y;}
double find_intersection(pair<Point,Point>&a,pair<Point,Point>&b){
    double m1=slope(a);
    double m2=slope(b);
    double c1= intercept(a,m1);
    double c2= intercept(b,m2);
    return (c2-c1)/(m1-m2);
}
double length(pair<Point,Point>&post){ return post.second.x-post.first.x;}
double area(pair<Point,Point>&post){	return 0.5*(post.first.y+post.second.y)*(post.second.x-post.first.x);}
static bool compare(pair<Point,Point>&a,pair<Point,Point>&b){return (a.first.x<b.first.x);}

void milao(pair<Point,Point>&a,pair<Point,Point>&b,int &i,int &j,vector<pair<Point,Point>>&ans){
    if(abs(a.first.x-a.second.x)<=epsilon){i++;return;}
    if(abs(b.first.x-b.second.x)<=epsilon){j++;return;}
    double m1= slope(a);
    double m2= slope(b);
    double int_x=find_intersection(a,b);
    if(b.first.x >= a.second.x){
        ans.push_back(a);
        i++;
        return;
    }
    if(abs(m1-m2)<=epsilon || int_x < b.first.x || int_x > min(a.second.x,b.second.x)){
        // ek hi line koi choose hoga
        double t=find_val(a,b.first.x);
        if(t>=b.first.y){ // a is upar
            if(a.second.x < b.second.x){
                b.first.y = find_val(b,a.second.x);
                b.first.x = a.second.x;
                ans.push_back(a);
                i++;
            }
            else j++;    
        }
        else{ // b is upar
            if(abs(a.first.x-b.first.x)>epsilon){
                ans.push_back({a.first,Point(b.first.x,t)});
                a.first.x = b.first.x;
                a.first.y = t;
            }
            milao(b,a,j,i,ans);
        }
        return;
    }
    if(m1<m2){ // b is dominating // yaha intersection hoga actual me
        if(abs(a.first.x - int_x)>epsilon)ans.push_back({a.first,Point(int_x,find_val(a,int_x))});
        if(b.second.x > a.second.x) {
            b.first.y = find_val(b,int_x);
            b.first.x = int_x;
            i++;
        }
        else{
            if(abs(int_x-b.second.x)>epsilon) ans.push_back({Point(int_x,find_val(a,int_x)),b.second});
            a.first.y = find_val(a,b.second.x);
            a.first.x = b.second.x;
            j++;
        }
    }
    else if(m1>m2){ // a is dominating
        // yaha intersection hoga actual me
        double t=find_val(a,b.first.x);
        if(abs(a.first.x-b.first.x)>epsilon){
            ans.push_back({a.first,Point(b.first.x,t)});
            a.first.x = b.first.x;
            a.first.y = t;
        }
        milao(b,a,j,i,ans);
    }
}
void merge(vector<pair<Point,Point>>&a,vector<pair<Point,Point>>&b,vector<pair<Point,Point>>&ans){
    int i=0;
    int j=0;
    int m=a.size();
    int n=b.size();
    while(i<m && j<n){
        pair<Point,Point>&trap1=a[i];
        pair<Point,Point>&trap2=b[j];
        if(trap1.first.x < trap2.first.x) milao(trap1,trap2,i,j,ans);
        else milao(trap2,trap1,j,i,ans);   
    }
    while(i<m) {if(a[i].first.x != a[i].second.x) ans.push_back(a[i]);i++;}
    while(j<n) {if(b[j].first.x != b[j].second.x) ans.push_back(b[j]);j++;}
}
vector<pair<Point,Point>> mergesort(vector<pair<Point,Point>> &posters,int l,int r){
    if(l>r) return {};
    if(l==r) return {posters[l]};
    int mid = l+(r-l)/2;
    vector<pair<Point,Point>> a=mergesort(posters,l,mid);
    vector<pair<Point,Point>> b=mergesort(posters,mid+1,r);
    vector<pair<Point,Point>> ans;
    merge(a,b,ans);
    return ans;
}
double length_covered(vector <pair<Point, Point>>&posters){
	double ans=length(posters[0]);
	double maxlength=posters[0].second.x;
	for(int i=1;i<posters.size();i++){
		ans+= length(posters[i]);
		if(posters[i].first.x < maxlength) ans-= min(posters[i].second.x,maxlength)-posters[i].first.x;
		maxlength=max(maxlength,posters[i].second.x);
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	double a,b,c,d;
	vector <pair<Point, Point>> posters; 
	for(int i=0; i<n; i++){
		cin >> a;
		cin >> b;
		cin >> c;
		cin >> d;
        if(abs(a-c)<=epsilon) continue;                 // skipping vertical lines
		posters.push_back(make_pair(Point(a,b), Point(c,d)));	
	}
	// sort(posters.begin(),posters.end(),compare);         // sort bhi krne ki jroorat ni h merging takes care
    vector<pair<Point,Point>> ans=mergesort(posters,0,posters.size()-1);
    double s=0;
    double l=0;
    for(int i=0;i<ans.size();i++){
        // cout<<ans[i].first.x<<" "<<ans[i].first.y<<" "<<ans[i].second.x<<" "<<ans[i].second.y<<endl;
        s+=area(ans[i]);
        l+=ans[i].second.x - ans[i].first.x;
    }
    // double lengthCovered = length_covered(posters); 
    // cout<<static_cast<int>(lengthCovered)<<endl;
    cout<<static_cast<int>(l)<<endl;
    cout<<static_cast<int>(s)<<endl;
    return 0;
}
