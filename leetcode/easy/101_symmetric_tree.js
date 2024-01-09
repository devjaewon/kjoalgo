/**
 * @description
 *  bfs 탐색을 통해 서로 대칭형태를 가지는지 확인하는 문제
 *  유의해야할 점은
 *  대칭형태를 체크하기 위해서 index, length, depth 값을 알아야한다.
 * 
 *  더 좋은 방식이 있을지는 확인이 필요함
 * 
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function(root) {
    let siblings = [];
    let prevDepth = 0;

    const complete = doBfs(
        root,
        (
            node,
            {
                length,
                depth,
                index,
            },
        ) => {
            if (depth !== prevDepth) {
                siblings = [];
                prevDepth = depth;
            }
            if (index < length / 2) {
                siblings.push(node);
                return true;
            }

            const mirroredNode = siblings[length - 1 - index];

            return mirroredNode?.val === node?.val;
        },
    );

    return complete;
};

function doBfs(treeNode, callback) {
    let depth = 1;
    let children = [treeNode];

    callback(treeNode, { length: 1, depth, index: 0 });
    depth++;

    while (children.length > 0) {
        const next = [];

        for (let i = 0; i < children.length; i++) {
            const node = children[i];
            
            if (!node) {
                continue;
            }

            if (node.left) {
                next.push(node.left);
            } else {
                next.push(null);
            }
            if (node.right) {
                next.push(node.right);
            } else {
                next.push(null);
            }
        }

        for (let i = 0; i < next.length; i++) {
            const continueLoop = callback(next[i], { length: next.length, depth, index: i });

            if (!continueLoop) {
                return false;
            }
        }
        
        children = next;
        depth++;
    }

    return true;
}
