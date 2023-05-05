* take a root note
* while(root){
* take root's val
* find if(root->left)
* go to right most and connect with the root
* then make root = root->left;
* if !root->left, root = root->right;
* if while finding right most if you will connected with the root  node then remove it and make root = root->right;
* at last print the values;