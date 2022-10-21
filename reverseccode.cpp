string reverseWord(string str){
   
  int j=0; 
    string s="";
  for(int i=(str.size())-1;i>=0;i--){
      
      cout<<str[i];
      s[j]+=str[i];
      j++;
  }
  
  return s;
}
