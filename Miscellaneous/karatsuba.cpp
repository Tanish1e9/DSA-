#include<iostream>
#include<string>
using namespace std;
int makeEqualLength(string &num1, string &num2){
	while(num1.size()<num2.size()){
		num1 = '0' + num1;
	}
	while(num2.size()<num1.size()){
		num2 = '0' + num2;
	}
	if(num1.size()%2==1){
		num1= '0'+num1;
		num2= '0'+num2;
	}
	return num1.size();
}
void addendzeros(string &s,int n){
	for(int c=0;c<n;c++) s+='0';
}
string addStrings(string num1, string num2) {
	if(num1=="0") return num2;
	if(num2=="0") return num1;
	int m= num1.size();
	int n= num2.size();
	string ans(max(m,n)+1,'0');
	int k= ans.size()-1;
	int i= num1.size()-1;
	int j= num2.size()-1;
	int c=0;
	while(i>=0 && j>=0){
		int d=(num1[i]-'0') + (num2[j]-'0');
		ans[k] = (d + c)%10 + '0';
		c= (d+c)/10;
		i--;j--;k--;
	}
	while(i>=0){
		int d=(num1[i]-'0');
		ans[k] = (d + c)%10 + '0';
		c= (d+c)/10;
		i--;k--;
	}
	while(j>=0){
		int d=(num2[j]-'0');
		ans[k] = (d + c)%10 + '0';
		c= (d+c)/10;
		j--;k--;
	}
	ans[0] = '0' + c;
	int z=0;
	for(;z<ans.size();z++){
		if(ans[z]!='0') break;
	}
	string final(ans.begin()+z,ans.end());
	return final;
}
string subtract(string& num1,string& num2){
	// Written with the assumption that num1 > num2 ... Also, you can't directly compare num1 and num2 since they are strings
	if(num1==num2) return "0";
	string ans(num1.size(),'0');
	int i=num1.size()-1;
	int j=num2.size()-1;
	int k=ans.size()-1;
	while(i>=0 && j>=0){
		int m = num1[i] -'0';
		int n = num2[j] -'0';
		if(m<n){
			int d=1;
			while(num1[i-d]=='0')d++;
			num1[i-d] = num1[i-d]-1;
			while(d>1){
				d--;
				num1[i-d] = '9';
			}
			m += 10;
		}
		ans[k] = m-n+'0';
		k--;i--;j--;
	}
	while(i>=0){
		ans[k] = num1[i];
		k--;i--;
	}
	int z=0;
	for(;z<ans.size();z++){
		if (ans[z]!='0') break;
	}
	string final(ans.begin()+z,ans.end());
	return final;
}
string multiply(string num1, string num2) {
	if(num1=="0" || num2=="0") return "0";
	if(num1.size()==1 && num2.size()==1){
		int d=(num1[0]-'0') * (num2[0]-'0');
		string ans;
		ans += d%10 +'0';
		if(d/10!=0) {
			char x = d/10 +'0';
			ans = x+ans;
		}
		return ans;
	}
	int n=makeEqualLength(num1,num2);
	string xh(num1.begin(),num1.begin()+n/2);
	string xl(num1.begin()+n/2,num1.end());
	string yh(num2.begin(),num2.begin()+n/2);
	string yl(num2.begin()+n/2,num2.end());
	string s1=multiply(xh,yh);
	string s2=multiply(xl,yl);
	string s3= addStrings(multiply(xh,yl),multiply(xl,yh));
	// string s3= multiply(addStrings(xh,xl),addStrings(yh,yl));     
	// s3= subtract(s3,s1);
	// s3= subtract(s3,s2);
	// ye step imp h because isi se T(n) = 3T(n/2) + O(n) hota  wrna 4 multiplications agar ho jate to T(n)=4T(n/2)+O(n) yani O(n^2) hi ho jata
	addendzeros(s1,n);
	addendzeros(s3,n/2);
	return addStrings(addStrings(s1,s3),s2);
	// ans is xh * yh * b^n + xl*yl + (xl*yh + yl*xh )* b^n/2    //here b is base
}
int main(){
	// string num1= "13535613025";
	// string num2= "64424642177";
	// string num1="";
	// string num2="366213329703";
	string num1;
	string num2;
	cin>>num1>>num2;
	cout<< multiply(num1,num2)<<endl;
	// cout<<subtract(num1,num2);
	return 0;
}
