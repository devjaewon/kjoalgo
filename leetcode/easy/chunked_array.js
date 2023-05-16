/**
 * @description 
 *  <performance>
 *  1번. (floor(n / size) + n) * push 하는 것 보다
 *  2번. floor(n / size) * (push + slice) 하는 것이 더 빠르고 메모리 효율성이 높다.
 *  
 *  <why>
 *  단순 로직적으로는 1번이 더 빠를것 같은데
 *  JS는 배열의 크기가 고정이 아니고 Object 로서 여러 처리가 들어가기 때문에
 *  루프 비용보다 push, slice 비용이 큰게 아닐까 싶다.
 * 
 *  <then>
 *  Big-O 만 고려해서는 최적의 성능을 낼 수 없다.
 *  기본 api 내부구현을 함께 고민하자.
 * 
 * @param {Array<number>} arr 
 * @param {number} size 
 * @returns 
 */
var chunk = function(arr, size) {
    var chunkedArr = [];
    var index = 0;

    while (index < arr.length) {
        chunkedArr.push(arr.slice(index, index + size));
        index += size;
    }

    return chunkedArr;
}
