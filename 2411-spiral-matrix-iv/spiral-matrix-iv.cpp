/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> arr(m, vector<int>(n, -1));

        int minr = 0;
        int maxr = m - 1;
        int minc = 0;
        int maxc = n - 1;

        ListNode* temp = head;

        while (minr <= maxr && minc <= maxc) {

            // Left → Right
            for (int j = minc; j <= maxc; j++) {

                if (temp == NULL)
                    return arr;

                arr[minr][j] = temp->val;
                temp = temp->next;
            }

            minr++;

            // Top → Bottom
            for (int i = minr; i <= maxr; i++) {

                if (temp == NULL)
                    return arr;

                arr[i][maxc] = temp->val;
                temp = temp->next;
            }

            maxc--;

            // Right → Left
            if (minr <= maxr) {

                for (int j = maxc; j >= minc; j--) {

                    if (temp == NULL)
                        return arr;

                    arr[maxr][j] = temp->val;
                    temp = temp->next;
                }

                maxr--;
            }

            // Bottom → Top
            if (minc <= maxc) {

                for (int i = maxr; i >= minr; i--) {

                    if (temp == NULL)
                        return arr;

                    arr[i][minc] = temp->val;
                    temp = temp->next;
                }

                minc++;
            }
        }

        return arr;
    }
};