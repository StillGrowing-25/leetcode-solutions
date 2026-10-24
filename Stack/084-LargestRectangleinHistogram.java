class Solution {
    public int largestRectangleArea(int[] heights) {
        int[] ans = new int[heights.length];
        Stack<Integer> st = new Stack<>();
        int n = heights.length;
        int max =0;

        for(int i =n-1; i>=0;i--){
            while(!st.isEmpty() && heights[st.peek()]>=heights[i])
                st.pop();
            if(!st.isEmpty()){
                ans[i] = st.peek();
            }else{
                ans[i]=n;
            }
            st.push(i);
        }
        st.clear();
        for(int i =0; i<n;i++){
            while(!st.isEmpty() && heights[st.peek()]>=heights[i])
                st.pop();
            if(!st.isEmpty()){
                ans[i]=ans[i]-st.peek()-1;
            }
            max = Math.max(ans[i]*heights[i],max);
            st.push(i);
        }return max;
    }
}
