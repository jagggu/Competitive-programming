struct TrieNode {
    map<char, TrieNode*> child;
    bool isEnd;
    map<char, int> num;
};

// Declare root node
struct TrieNode* root;

// Function to create New Trie Node
struct TrieNode* getNewTrieNode()
{
    struct TrieNode* temp = new TrieNode;
    temp->isEnd = false;
    return temp;
}

// Function to insert a string in trie
void insert(string word){
    // To hold the value of root
    struct TrieNode* current = root;

    // To hold letters of the word
    char s;

    // Traverse through strings in list
    for (int i = 0; i < word.length(); i++) {
        s = word[i];

        // If s is not present in the character field of current node
        if (current->child.find(s) == current->child.end()) {
            // Get new node
            struct TrieNode* p = getNewTrieNode();

            // Insert s in character field of current node with reference to node p
            (current->child)[s] = p;

            // Insert s in num field of current node with value 1
            (current->num)[s] = 1;
        }
        else {
            // Increment the count corressponding to the character s
            current->num[s] = (current->num)[s] + 1;
        }

        // Go to next node
        current = (current->child)[s];
    }
    current->isEnd = true;
}

// Function to count the number of words in trie with given prefix
int query(string prefix){

    struct TrieNode* current = root;
    char s;

    // Initialize the ans = 0
    int ans = 0;

    for (int i = 0; i < prefix.size(); i++) {
        s = prefix[i];

        // If the complete prefix isnot present in the trie
        if (current->child.find(s) == current->child.end()) {

            // Make ans 0 and break out of loop
            ans = 0;
            break;
        }

        // Update the ans
        ans = (current->num)[s];

        // Go to next node
        current = (current->child)[s];
    }

    return ans;
}


vector<int> Solution::solve(vector<string> &A, vector<string> &B) {
    int Q = B.size();
  int M = B[0].size();
  int N = A.size();

  root = getNewTrieNode();

  // Construct trie containing the words whose prefix of length l matches to it suffix of length l
  for(int i = 0; i < N; i++){
    if(A[i].size() < M){
      continue;
    }
    string s = A[i];
    int x = 0, y = s.size() - M;
    int flag = 0;
    while(x < M){
      if(s[x] != s[y]){
        flag = 1;
        break;
      }
      x++;
      y++;
    }
    if(flag){
      continue;
    }
    insert(s);
  }
  vector<int> ans;
  for(int i = 0; i < Q; i++){
      assert(B[i].size() == M);
    ans.push_back(query(B[i]));
  }
  return ans;
}