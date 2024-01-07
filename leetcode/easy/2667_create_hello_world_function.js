/**
 * @description
 *  아마 functional programming 이 가능하다는 것을 보여주려는 문제가 아닐까 싶다.
 * 
 *  <performance>
 *  기본 scaffold 에서는 return 하는 function 에 ...args 인자를 rest parameter 로 받고 있었는데
 *  이 표현식을 지우니까 메모리가 소폭 향상 되었다.
 *  
 *  <why>
 *  아마 처음에 함수의 컨텍스트를 형성할때 argument를 객체화 해서 갖고 있는 비용이 아닐까 싶다
 * 
 *  <then>
 *  불필요한 변수나 인자는 모두 정의하지 말자
 * 
 * @returns 
 */
var createHelloWorld = function() {
    return function() {
        return "Hello World";
    }
};