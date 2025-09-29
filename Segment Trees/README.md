- child nodes ka lazy update tabhi kro jab (low!=high) ho i.e. check ki non-leaf node hona chahye to prevent runtime error
- always in case of lazy propagation the first thing you should do in a update / query is addressing the lazy part
uske baad hi fir check kro ki leaf h ya fir requested range se no overlap h to return
isse kya h ki kisi range ka answer galat aa skta because uska ek child update hi ni hua h  
- Also in case of update and complete overlap, sirf lazy[ind] me daal die sochke ki update ho hi jayega ye galat h. Point is ki update me bhi tree update hota h wo updation ho hi ni payega because lazy me daal die ho thus leading to wrong answer. So, complete overlap me update krdo seg[ind] ko then hi baccho me lazy propagation kro.
- Distinct elements ke saare questions :-
  - Distinct colors (Trees me)
  - Distinct Values Queries 1, 2 (Range Queries me)
  - Distinct Values Sum (Additional Problems 1 me)
  - https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/description/
  - Distinct Values Subarrays (Sorting Searching me)
  - https://www.geeksforgeeks.org/problems/make-array-elements-unique--170645/1
