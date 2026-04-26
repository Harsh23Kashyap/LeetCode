import java.util.*;

// Eviction Policy Interface
interface EvictionPolicy<K> {
    void keyAccessed(K key);
    K evictKey();
}

// Doubly Linked List Node
class Node<K> {
    K key;
    Node<K> prev, next;

    Node(K key) {
        this.key = key;
    }
}

// Doubly Linked List
class DoublyLinkedList<K> {
    private Node<K> head, tail;

    public DoublyLinkedList() {
        head = new Node<>(null);
        tail = new Node<>(null);
        head.next = tail;
        tail.prev = head;
    }

    public Node<K> addFirst(K key) {
        Node<K> node = new Node<>(key);

        node.next = head.next;
        head.next.prev = node;

        head.next = node;
        node.prev = head;

        return node;
    }

    public void remove(Node<K> node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public Node<K> removeLast() {
        if (tail.prev == head) return null;

        Node<K> last = tail.prev;
        remove(last);
        return last;
    }
}

// LRU Eviction Policy
class LRUEvictionPolicy<K> implements EvictionPolicy<K> {

    private Map<K, Node<K>> map;
    private DoublyLinkedList<K> dll;

    public LRUEvictionPolicy() {
        map = new HashMap<>();
        dll = new DoublyLinkedList<>();
    }

    public void keyAccessed(K key) {
        if (map.containsKey(key)) {
            dll.remove(map.get(key));
        }
        Node<K> node = dll.addFirst(key);
        map.put(key, node);
    }

    public K evictKey() {
        Node<K> node = dll.removeLast();
        if (node == null) return null;

        map.remove(node.key);
        return node.key;
    }
}

// Main Cache Class (your required structure)
class LRUCache {

    private final int capacity;
    private Map<Integer, Integer> storage;
    private EvictionPolicy<Integer> evictionPolicy;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.storage = new HashMap<>();
        this.evictionPolicy = new LRUEvictionPolicy<>();
    }

    public int get(int key) {
        if (!storage.containsKey(key)) return -1;

        evictionPolicy.keyAccessed(key);
        return storage.get(key);
    }

    public void put(int key, int value) {

        if (storage.containsKey(key)) {
            storage.put(key, value);
            evictionPolicy.keyAccessed(key);
            return;
        }

        if (storage.size() >= capacity) {
            Integer evict = evictionPolicy.evictKey();
            if (evict != null) {
                storage.remove(evict);
            }
        }

        storage.put(key, value);
        evictionPolicy.keyAccessed(key);
    }
}