package com.company;

public class UserSolution {

    private final static int MAX_NODE = 10000;

    private Node[] node = new Node[MAX_NODE];
    private int nodeCnt = 0;
    private Node head;

    public Node getNode(int data) {
        node[nodeCnt] = new Node(data);
        return node[nodeCnt++];
    }

    public void init() {
        head = null;
        nodeCnt = 0;
    }

    public void addNode2Head(int data) {
        if(head==null){
            head = getNode(data);
        } else {
            Node node = getNode(data);
            node.next = head;
            head = node;
        }
    }

    public void addNode2Tail(int data) {
        if(head==null){
            head = getNode(data);
        } else {
            Node node = getNode(data);
            Node tmp = head;
            while(tmp.next!=null){
                tmp = tmp.next;
            }
            tmp.next = node;
        }
    }

    public void addNode2Num(int data, int num) {
        if(head==null){
            head = getNode(data);
        } else {
            Node node = getNode(data);
            if(num==1){
                node.next = head;
                head = node;
            } else {
                Node tmp = head;
                for(int i=num-2; i>0; --i){
                    tmp = tmp.next;
                }
                node.next = tmp.next;
                tmp.next = node;
            }
        }
    }

    public void removeNode(int data) {
        if(head==null){
        } else {
            Node tmp = head;
            if(head.data == data){
                head = head.next;
                nodeCnt--;
            } else {
                while(tmp.next!=null){
                    if(tmp.next.data == data){
                        tmp.next = tmp.next.next;
                        nodeCnt--;
                        break;
                    }
                    tmp = tmp.next;
                }
            }
        }
    }

    public int getList(int[] output) {
        Node tmp = head;
        int ans = 0;
        for(int i=0; i<nodeCnt; ++i){
            output[i] = tmp.data;
            tmp = tmp.next;
            ans++;
        }
        return ans;
    }
}
class Node {
    public int data;
    public Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}