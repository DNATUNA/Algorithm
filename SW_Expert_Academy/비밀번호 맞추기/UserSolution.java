package com.company;

public class UserSolution {
    public final static int N = 4;

    public void doUserImplementation(int guess[]) {
        LinkedList list = new LinkedList();

        for(int i=0; i<10; ++i){
            for(int j=0; j<10; ++j){
                if(i==j) continue;
                for(int k=0; k<10; ++k){
                    if(k==i || k==j) continue;
                    for(int l=0; l<10; ++l){
                        if(l==i || l==j || l==k) continue;
                        list.insertNode(new int[]{i, j, k, l});
                    }
                }
            }
        }
        ListNode head = list.getHead();
        while(true){
            Solution.Result queryResult = Solution.query(head.data);
            if(queryResult.hit==4) break;

            ListNode next = head.link;
            while(next.link!=null){
                Solution.Result checkResult = check(head.data, next.data);
                if (queryResult.hit != checkResult.hit || queryResult.miss != checkResult.miss) {
                    list.deleteNode(next);
                    continue;
                }
                next = next.link;
            }
            list.deleteNode(head);
        }
        for(int i=0; i<4; ++i){
            guess[i] = head.data[i];
        }
    }

    public Solution.Result check(int[] headData, int []data){
        Solution.Result result = new Solution.Result();
        int[] check = new int[10];

        for(int i=0; i<4; ++i){
            check[headData[i]]++;
        }

        for(int i=0; i<4; ++i){
            if(headData[i]==data[i]) result.hit++;
            else{
                if(check[data[i]]==1) result.miss++;
            }
        }
        return result;
    }
}

class ListNode {
    public int[] data;
    public ListNode link;

    public ListNode(int[] data) {
        this.data = data;
        this.link = link;
    }

    public int[] getData() {
        return this.data;
    }
}

class LinkedList {
    private ListNode head;

    public LinkedList() {
        head = null;
    }

    public void insertNode(int[] data){
        ListNode newNode = new ListNode(data);
        if(head == null){
            this.head = newNode;
        } else {
            ListNode tempNode = head;
            while (tempNode.link != null) {
                tempNode = tempNode.link;
            }
            tempNode.link = newNode;
        }
    }

    public void deleteNode(ListNode node){
        ListNode tempNode = node.link;
        node.data = tempNode.data;
        node.link = tempNode.link;
    }

    public ListNode getHead() {
        return this.head;
    }
}