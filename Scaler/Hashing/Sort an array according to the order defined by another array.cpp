/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

unordered_map<int,int> m;

bool myComparator(int a, int b) {
	return m[a] < m[b];
}


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

	

	int order = 1;
    sort(A.begin(),A.end());
	for(int ele : B) {
		m[ele] = order;
		order++;
	}

	for(int ele : A) {
		if(m.find(ele) == m.end()) {
		    //cout<<ele<<' '<<endl;
			m[ele] = order;
			order++;
		}
	}
	
	/*
	for(int ele : A) {
	    cout<<m[ele]<<' ';
	}
	cout<<endl;
    */
    
	sort(A.begin(),A.end(),myComparator);
	/*
	for(int ele : A) {
	    cout<<ele<<' ';
	}
	cout<<endl;
	*/
	m.clear();
	vector<int> res;
	res = A;
	return A;
}


