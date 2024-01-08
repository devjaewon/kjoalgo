/**
 * @description
 *  구현은 closer 개념을 활용하면 간단하다.
 *  최적화 케이스가 요구되었는데 아래 항목을 고려하면 O(1)로 줄일 수 있다.
 *  - Tree + Map 탐색
 */
function memoize(fn) {
    var cacheTree = {
        root: true,
        result: null,
        children: {}, // TODO: map으로 변환 필요
    };

    function getChildNode(cache, arg) {
        if (arg in cache.children) {
            return cache.children[arg];
        } else {
            return null;
        }
    }

    function getCacheLeafNode(cache, args) {
        let leafNode = null;
        for (let i = 0; i < args.length; i++) {
            leafNode = getChildNode(cache, args[i]);
            if (leafNode === null) {
                return null;
            }
            cache = leafNode;
        }

        return leafNode;
    }

    function initChildNode(cache, arg) {
        cache.children[arg] = {
            root: false,
            result: null,
            children: {},
        };

        return cache.children[arg];
    }

    function setCache(cache, args, result) {
        let cacheNode;
        for (let i = 0; i < args.length; i++) {
            let arg = args[i];
            cacheNode = getChildNode(cache, arg);
            if (cacheNode === null) {
                cacheNode = initChildNode(cache, arg);
            }

            cache = cacheNode;
        }

        if (cacheNode) {
            cacheNode.result = result;
        }
    }
  
  return function(...args) {
      let leafNode = getCacheLeafNode(cacheTree, args);
      let result = leafNode !== null ? leafNode.result : null;

      if (leafNode === null) {
          result = fn(...args);
          setCache(cacheTree, args, result);
      }

      return result;
  }
}

let callCount = 0;
const memoizedFn = memoize(function (a, b) {
  callCount += 1;
  return a + b;
})
console.log(memoizedFn(2, 3)) // 5
console.log(memoizedFn(2, 3)) // 5
console.log(callCount) // 1 
 