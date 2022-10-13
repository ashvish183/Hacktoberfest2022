class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if(head == null || head.next == null){
            return null;
        }
        
        int size = 0;
        ListNode curr = head;
        while(curr != null){
            curr = curr.next;
            size++;
        }
        if(size == 2){
            head.next = null;
            return head;
        }
        
        
        if(size % 2 == 0){
            int index = size/2;
            ListNode prev = head;
            int i = 1;
            while(i<index){
                prev = prev.next;
                i++;
            }
            prev.next = prev.next.next;
            return head;
        }
        if(size % 2 != 0){
            int index = (size+1)/2;
            ListNode prev = head;
            int i = 1;
            while(i<index-1){
                prev = prev.next;
                i++;
            }
            prev.next = prev.next.next;
            return head;
    }
        return head;
}
}
