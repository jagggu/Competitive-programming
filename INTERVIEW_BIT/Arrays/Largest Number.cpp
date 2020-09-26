/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/


bool myComparator(string a, string b) {
	return (a+b) > (b+a);
}

string Solution::largestNumber(const vector<int> &A) {

	vector<string> arr;

	for(int ele : A) {
		arr.push_back(to_string(ele));
	}

	sort(arr.begin(),arr.end(),myComparator);

	int i = 0;
	int n = arr.size();

	while(i<n && arr[i] == "0") {
		i++;
	}

	if(i == n) {
		return "0";
	}

	string res;
	for(int k = i;k<n;k++) {
		res += arr[k];
	}

	return res;

}
