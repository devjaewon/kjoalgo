/**
 * @description
 *  javascript 의 비동기 처리 방식을 이해하고 있는지 확인하는 문제로 보임
 * 
 * @param {number} millis
 * @return {Promise}
 */
function sleep(millis) {
    return new Promise(resolve => setTimeout(resolve, millis));
}
