# Kth distance
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an unsorted array <strong>Arr</strong> of size <strong>N</strong> that may contain duplicates. Also given a number <strong>K</strong> which is smaller than size of array. Find if array contains duplicates within <strong>K</strong>&nbsp;distance.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
K = 3, N = 8
Arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
<strong>Output:</strong> False
<strong>Explanation:</strong> 
All duplicates are more than k distance
away.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
K = 3, N = 6
Arr[] = {1, 2, 3, 1, 4, 5}
<strong>Output:</strong> True
<strong>Explanation: </strong>1 is repeated at distance 3.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>checkDuplicatesWithinKâ€‹()</strong>&nbsp;which takes the array of integers&nbsp;<strong>arr[],</strong><strong>&nbsp;n&nbsp;</strong>and <strong>k&nbsp;</strong>as parameters and returns boolean&nbsp;denoting the answer.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>6</sup><br>
1 ≤ K ≤ N<br>
1 ≤ Arr[i] ≤ 10<sup>7</sup></span></p>

<p>&nbsp;</p>
</div>