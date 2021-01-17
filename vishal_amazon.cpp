bool helper(tnode* root1, tnode* root2) {
    if(!root1 && !root2) {
        return true;
    }

    if(!root1 || !root2) {
        return false;
    }

    if(root1->value != root2->value) {
        return false;
    }

    return helper(root1->left, root2->left) && helper(root1->right, root2->right);
}

int isSubTree(tnode* root1, tnode* root2) {
    if(!root1) {
        return -1;
    }

    if(helper(root1, root2)) {
        return 1;
    }

    return (isSubTree(root1->left, root2)==1 || isSubTree(root1->right, root2)==1)?1:-1;
}




int countPairs(int numCount, vector<int> ratingValues, int target) {
    unordered_map<int,int> count;

    for(int i: ratingValues) {
        count[i]++;
    }

    int ret=0;

    for(int i: ratingValues) {
        count[i]--;

        if(count[target - i]) {
            ret++;
            count[i]--;
            count[target-i]--;
        }

        count[i]++;
    }

    return ret;
}