/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	Stack<Integer> l1Stack = buildStack(l1);
	Stack<Integer> l2Stack = buildStack(l2);
	ListNode temp = null;

	int carry = 0;
	while (!l1Stack.isEmpty() && !l2Stack.isEmpty()) {
		int a = l1Stack.pop();
		int b = l2Stack.pop();
		int sum = a + b + carry;
		carry = sum > 9 ? 1 : 0;
		sum %= 10;

		ListNode node = new ListNode(sum);
		node.next = temp;
		temp = node;
	}

	while (!l1Stack.isEmpty()) {
		int sum = l1Stack.pop() + carry;
		carry = sum > 9 ? 1 : 0;
		sum %= 10;

		ListNode node = new ListNode(sum);
		node.next = temp;
		temp = node;
	}

	while (!l2Stack.isEmpty()) {
		int sum = l2Stack.pop() + carry;
		carry = sum > 9 ? 1 : 0;
		sum %= 10;

		ListNode node = new ListNode(sum);
		node.next = temp;
		temp = node;
	}

	if (carry == 1) {
		ListNode node = new ListNode(1);
		node.next = temp;
		temp = node;
	}
	return temp;
}

private Stack<Integer> buildStack(ListNode l1) {
	Stack<Integer> stack = new Stack<>();
	while (l1 != null) {
		stack.push(l1.val);
		l1 = l1.next;
	}
	return stack;
}
}