 // Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[]
int getSum(int BITree[], int index){
    int sum = 0; // Initialize result
 
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse ancestors of BITree[index]
    while (index>0){
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BITree) at given
// index in BITree.  The given value 'val' is added to
// BITree[i] and all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse all ancestors and add 'val'
    while (index <= n){
        // Add 'val' to current node of BI Tree
        BITree[index] += val;
 
        // Update index to that of parent in update View
        index += index & (-index);
    }
}
 
// Returns the sum of array from [0, x]
int sum(int x, int BITTree1[], int BITTree2[]){
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}
 
 
void updateRange(int BITTree1[], int BITTree2[], int n, int val, int l, int r){
    // Update Both the Binary Index Trees
    // As discussed in the article
 
    // Update BIT1
    updateBIT(BITTree1,n,l,val);
    updateBIT(BITTree1,n,r+1,-val);
 
    // Update BIT2
    updateBIT(BITTree2,n,l,val*(l-1));
    updateBIT(BITTree2,n,r+1,-val*r);
}
 
int rangeSum(int l, int r, int BITTree1[], int BITTree2[]){
    // Find sum from [0,r] then subtract sum
    // from [0,l-1] in order to find sum from
    // [l,r]
    return sum(r, BITTree1, BITTree2) -
           sum(l-1, BITTree1, BITTree2);
}
 
 
// Driver Program to test above function
int main(){
	updateRange(BITTree1,BITTree2,n,val,l,r);
	rangeSum(l,r,BITTree1,BITTree2);
    return 0;
}
