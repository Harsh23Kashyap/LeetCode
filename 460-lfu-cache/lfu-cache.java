class LFUCache {
    static class Node{
        int key;
        int value;
        Node prev;
        Node next;
        int frequency;
        Node(int key, int value){
            this.key=key;
            this.value=value;
            this.prev=null;
            this.next=null;
            this.frequency=1;
        }
    }

    static class DLL{
        Node head;
        Node tail;
        int size=0;
        DLL(){
            head= new Node(-1,-1);
            tail=new Node(-1,-1);
            head.next=tail;
            tail.prev=head;
            this.size=0;
        }

        void removeNode(Node currNode){
            Node prevNode=currNode.prev;
            Node nextNode=currNode.next;
            prevNode.next=nextNode;
            nextNode.prev=prevNode;
            size--;
        }
        Node removeTail(){
            Node currNode=tail.prev;
            removeNode(currNode);
            return currNode;
        }
        void addAtFront(Node currNode){
            Node headNext=head.next;
            headNext.prev=currNode;
            currNode.next=headNext;
            head.next=currNode;
            currNode.prev=head;
            size++;
        }


        boolean empty(){
            return size==0;
        }

    }
    private final int capacity;
    int currsize;
    private int minFrequency;
    Map<Integer, Node> cache;
    Map<Integer, DLL> freqMap;


    public LFUCache(int capacity) {
        this.capacity=capacity;
        this.cache= new HashMap<>();
        this.freqMap= new HashMap<>();
        this.minFrequency=0;
    }
    
    public int get(int key) {
        if(!cache.containsKey(key)){
            return -1;
        }

        Node curr=cache.get(key);
        updateFrequency(curr);

        return curr.value;
    }
    
    public void put(int key, int value) {
        if(capacity==0){
            return;
        }

        if(cache.containsKey(key)){
            Node curr=cache.get(key);
            
            updateFrequency(curr);
            curr.value=value;
            return;
        }


        if(cache.size()>=capacity){
            DLL currdl=freqMap.get(minFrequency);
            Node curr=currdl.removeTail();
            cache.remove(curr.key);
        }

        Node currNode= new Node(key,value);

        minFrequency=1;
        freqMap.putIfAbsent(1, new DLL());

        freqMap.get(1).addAtFront(currNode);
        cache.put(key,currNode);


    }

    void updateFrequency(Node curr){
        int currFrequency=curr.frequency;
        freqMap.get(currFrequency).removeNode(curr);
        if(currFrequency==minFrequency && freqMap.get(currFrequency).empty()){
            minFrequency++;
        }
        // curr.frequency++;
        
        curr.frequency++;
        freqMap.putIfAbsent(curr.frequency, new DLL());
        freqMap.get(curr.frequency).addAtFront(curr);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */