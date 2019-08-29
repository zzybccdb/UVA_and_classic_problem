// 题目说明: 
// 输入一个数组,假定数组中存在两个数之和为 target
// 输出这两个数的 index
let search = (arr=[1,2,3], target=5) => {
    let obj = {};
    for(let i = 0; i < arr.length; i++){
        if(obj[target - arr[i]] === undefined){
            obj[arr[i]] = i;
        }
        else{
            return [obj[arr[i]],i];
        }
    }
    return [];
}