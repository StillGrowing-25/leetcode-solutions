class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int start = 0, end = 0, n = nums.length;
        Deque<Integer> dq = new ArrayDeque<>();
        int[] ans = new int[n-k+1];
        int index=0;
        while(end<n){
            while(!dq.isEmpty() && nums[end]>dq.peekLast())
                dq.pollLast();
            dq.addLast(nums[end]);
            if(end-start+1 == k){
                ans[index]=dq.peekFirst();
                index++;
                if(dq.peekFirst() == nums[start])
                    dq.pollFirst();
                start++;
            }end++;
        }return ans;
    }
}
