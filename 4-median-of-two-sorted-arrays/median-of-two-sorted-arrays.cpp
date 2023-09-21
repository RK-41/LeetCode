class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 21.09.23 POTD

        int n1=nums1.size(), n2=nums2.size();
        int half = (n1+n2)/2;
        
        for(auto b: nums2){
            nums1.push_back(b);
        }

        sort(nums1.begin(), nums1.end());

        if((n1+n2)%2==1)
            return nums1[half];

        return (double)(nums1[half-1]+nums1[half])/2;

    //     int i=0, j=0;

    //     while(i<n1 && j<n2){
    //         if(nums1[i] <= nums2[j])
    //             i++;
    //         else
    //             j++;

    //         if(--half == 0)
    //             break;
    //     }

    //     while(half>0 && i<n1){
    //         i++;
    //         half--;
    //     }

    //     while(half>0 && j<n2){
    //         j++;
    //         half--;
    //     }

    //     if((n1+n2)%2==1){
    //         if(i<n1 && j<n2)
    //             return min(nums1[i],nums2[j]);
    //         else if(i<n1)
    //             return nums1[i];
            
    //         // else
    //         return nums2[j];
    //     }
    //     else{
    //         if(i<n1 && j<n2){
    //             return (nums1[i]+nums2[j])/2;
    //         }
    //         else if(j<n2){
    //             if(j==0)
    //                 return (nums1[i-1]+nums2[0])/2;
    //         }
    //         else if(i<n1-1)
    //             return (nums1[i]+nums1[i+1])/2;
            
    //         // else
    //         return (nums2[j]+nums2[j+1])/2;
    //     }
    }
};