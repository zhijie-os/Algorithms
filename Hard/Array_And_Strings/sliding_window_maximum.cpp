class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> monotonic_queue;	// this will be a decreasing monotonic queue
		vector<int> result;

		for(int i=0; i<nums.size(); i++)
		{
			// check if the leftmost element needs to be removed according to k
			if(monotonic_queue.front()==i-k)
				monotonic_queue.pop_front();
			
			// remove all the elements that are smaller than nums[i],
			// the rationale is that nums[i] is greater than those elements
			// those elements would never be consider the "max" within the lifetime of 
			// nums[i]. Since those elements have longtime shorter than nums[i]'s, we 
			// can safely remove them
			while(!monotonic_queue.empty() && nums[i]>nums[monotonic_queue.back()])
			{
				monotonic_queue.pop_back();
			}
			// enqueue nums[i]
			monotonic_queue.push_back(i);

			// if there are enough elements to fill the entire window
			// the maximum would always be front of the decreasing monotoni cqueue
			if(i>=k-1)
			{
				result.push_back(nums[monotonic_queue.front()]);	
			}

		}

		return result;
	}
};
