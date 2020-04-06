class Solution {
public:
    inline double divide(int a, int b) {
        return a - (a - b) / 2.0;
    }

    double findMedianOfArray(vector<int>& ary) {
        if (ary.size() % 2)
            return ary[ary.size() / 2];
        else
            return divide(ary[(ary.size()/2) - 1], ary[ary.size()/2]);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    for (auto i : nums1)
        cout << i << ' ';
    cout << endl;
    for (auto i : nums2)
        cout << i << ' ';
    cout << endl << endl;
        int median1, median2;
        if (!nums1.empty())
            median1 = nums1[nums1.size()/2];
        else return findMedianOfArray(nums2);

        if (!nums2.empty())
            median2 = nums2[nums2.size()/2];
        else return findMedianOfArray(nums1);

        if (nums1.size() == 1 && nums2.size() == 1) {
            return divide(nums1[0], nums2[0]);
        }

        if (median1 == median2) {
            if (nums1.size()%2 == 0 && nums2.size()%2 == 0) {
                int num = nums1[nums1.size()/2 - 1] > nums2[nums2.size()/2 - 1] ? nums1[nums1.size()/2 - 1] : nums2[nums2.size()/2 - 1];
                return divide(num, median1);
            }
            return median1;
        }

        else if (median1 < median2) {
            int left1 = nums1.size()/2;
            int right2 = nums2.size() - nums2.size()/2 - 1;
            if (left1 == 0) { //nums1只有一个元素
                int nums2_before = nums2[nums2.size()/2 - 1];
                if (median1 > nums2_before) {
                    if (nums2.size() % 2) //基数个
                        return divide(median1, median2);
                    else
                        return median1;
                }
                else {
                    if (nums2.size() % 2) //基数个
                        return divide(nums2_before, median2);
                    else
                        return nums2_before;
                }
            }
            if (right2 == 0) {
                for (auto i = nums2.begin(); i != nums2.end(); ++i)
                    nums1.push_back(*i);
                sort(nums1.begin(), nums1.end());
                return findMedianOfArray(nums1);
            }
            if (nums1.size()%2 == 0 && nums2.size()%2 == 0) { //如果都是偶数且n1中位数的前一个数比n2中位数前所有元素都大，则不能移除n1中位数前面的数
                int nums1_before = nums1[nums1.size()/2 - 1];
                int nums2_before = nums2[nums2.size()/2 - 1];
                if (nums1_before > nums2_before)
                    swap(nums1[nums1.size()/2 - 1], nums2[nums2.size()/2 - 1]);
            }
            if (left1 > right2) {
                vector<int> new1(nums1.begin()+right2, nums1.end());
                vector<int> new2(nums2.begin(), nums2.end()-right2);
                return findMedianSortedArrays(new1, new2);
            }
            else {
                vector<int> new1(nums1.begin()+left1, nums1.end());
                vector<int> new2(nums2.begin(), nums2.end()-left1);
                return findMedianSortedArrays(new1, new2);
            }
        }
        else
            return findMedianSortedArrays(nums2, nums1);
    }
};
