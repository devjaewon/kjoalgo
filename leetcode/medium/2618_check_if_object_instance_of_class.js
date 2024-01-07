/**
 * @description
 *  자바스크립트의 프로토타입 체이닝을 이해하고 있는지 확인하는 문제로 보인다.
 *  Primitive 타입의 경우 Object가 아니기 때문에 instanceof로 체크할 수 없는데
 *  이를 어떻게 해결할지 보는 문제 같다.
 * 
 *  처음에는 Primitive 타입을 모두 인스턴스로 변경해서 해결하려했었는데
 *  (ex. new String(obj))
 *  BigInt는 Constructor로 쓸 수 없게 설계되어 있다.
 * 
 *  그래서 직접 prototype 객체를 순회하면서 찾아야했다.
 *  한가지 알게된 건 __proto__ 대신 Object.getPrototype() 함수를 통해 해당 객체를 얻을 수 있다 점이다.
 *  대놓고 쓰지말라고 더블 언더바로 되어있는 프로퍼티에 접근하는게 찝찝했는데 좋다.
 * 
 *  ps. 프로토타입을 순회해도 NaN 같은 경우 Number constructor 를 사용하지 않는 문제가 있어서
 *  타입을 통해 object 로 변환하는 전처리를 추가했다.
 */
var checkIfInstanceOf = function(obj, classFunction) {
    switch (typeof obj) {
        case 'string':
            obj = new String(obj);
            break;
        case 'number':
            obj = new Number(obj);
            break;
        case 'boolean':
            obj = new Boolean(obj);
            break;
    }

    while (obj) {
        if (obj.constructor === classFunction) {
            return true;
        }

        obj = Object.getPrototypeOf(obj);
    }

    return false;
};
