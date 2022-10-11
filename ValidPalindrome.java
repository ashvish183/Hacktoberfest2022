// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
// and removing all non-alphanumeric characters, it reads the same forward and backward.
// Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

//Example:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

public class ValidPalindrome {

    public static void main(String[] args) {
        String str = "A man, a plan, a canal: Panama";
        if(isPalindrome(str)){
            System.out.println(str + "is a Palindrome");
        }
        else {
            System.out.println(str + "is Not a Palindrome");
        }
    }

    public static boolean isPalindrome(String s) {
        s = s.toLowerCase();
        String a = "";
        int n = s.length();
        for(int i = 0; i < n; i++){
            if((s.charAt(i) >= 97 && s.charAt(i) <= 122) || (s.charAt(i) >= 48 && s.charAt(i) <= 57)){
                a = a + s.charAt(i);
            }
        }
        int m = a.length();
		if(m==0 || m==1)
			return true;
		for(int i=0;i<m/2;i++){
			if(a.charAt(i)!=a.charAt(m-1-i))
				return false;
		}
		return true;
    }
}
