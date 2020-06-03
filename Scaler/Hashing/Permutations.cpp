
/*
Permutations
Problem Description
You are given two strings A and B of size N and M respectively. You have to find the count of all permutations of X present in Y as a substring. You can assume a string will have only lowercase letters. 


Problem Constraints
1 <= N < M <= 1e5


Input Format
Given two argument, A and B of type String.


Output Format
Return a single Integer X, i.e number of permutations of A present in B as a substring.


Example Input
X = "abc"
Y = "abcbacabc"


Example Output
5


Example Explanation
    Permutations of X that are present in Y as substring are
    1. abc
    2. cba
    3. bac
    4. cab
    5. abc
    so ans is 5.

 */



bool map_compare(unordered_map<char,int> xMap, unordered_map<char,int> yMap) {
    for(auto itr = xMap.begin();itr != xMap.end(); itr++) {
        if(itr->second != yMap[itr->first]) {
            return false;
        }
    }
    return true;
}

int Solution::solve(string A, string B) {

	unordered_map<char,int> xMap;
	unordered_map<char,int> yMap;
	int count = 0;
	for(auto ele : A) {
		xMap[ele]++;
	}

	int windowSize = A.length();

	int i;

	for(i = 0;i<windowSize;i++) {
		yMap[B[i]]++;
	}
	int j = 0;
	//i--;
	for( ; i<B.length();i++) {
	   // cout<<j<<' '<<i<<endl;
	   // cout<<yMap['a']<<' '<<yMap['b']<<' '<<yMap['c']<<endl;
	    // cout<<xMap['a']<<' '<<xMap['b']<<' '<<xMap['c']<<endl;
		/*
		if(isValid(j,i,xMap,yMap,B)) {
			count++;
		}
		*/
		if(map_compare(xMap,yMap)) {
		    count++;
		}
		yMap[B[j]]--;
		yMap[B[i]]++;
		j++;
	}
	
	if(map_compare(xMap,yMap)) {
	    count++;
	}
	
	return count;

}
