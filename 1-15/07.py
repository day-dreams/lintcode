class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Solution:

    """
    @param root: An object of TreeNode, denote the root of the binary tree.
    This method will be invoked first, you should design your own algorithm
    to serialize a binary tree which denote by a root node to a string which
    can be easily deserialized by your own "deserialize" method later.
    """

    def serialize(self, root):
        # write your code here

        rv = ""

        to_travel = []

        to_travel.append(root)

        while len(to_travel) != 0:

            node = to_travel[0]
            to_travel = to_travel[1:]

            if node is None:

                if len(rv) == 0:
                    rv += '#'
                else:
                    rv += ',#'

                continue

            if len(rv) == 0:
                rv += str(node.val)
            else:
                rv += ',' + str(node.val)

            to_travel.append(node.left)
            to_travel.append(node.right)

        return rv

    """
    @param data: A string serialized by your serialize method.
    This method will be invoked second, the argument data is what exactly
    you serialized at method "serialize", that means the data is not given by
    system, it's given by your own serialize method. So the format of data is
    designed by yourself, and deserialize it here as you serialize it in
    "serialize" method.
    """

    def deserialize(self, data):
        # write your code here

        if len(data) == 0 or data[0] == '#':
            return None

        print data

        values = data.split(',')
        v_index = 0

        nodes = []

        root = TreeNode(int(values[0]))
        nodes.append(root)
        v_index += 1

        while len(nodes) != 0:

            cur = nodes[0]
            nodes = nodes[1:]

            if values[v_index] == '#':
                cur.left = None
            else:
                cur.left = TreeNode(int(values[v_index]))
                nodes.append(cur.left)

            v_index += 1

            if values[v_index] == '#':
                cur.right = None
            else:
                cur.right = TreeNode(int(values[v_index]))
                nodes.append(cur.right)

            v_index += 1

        return root


def main():

    s = Solution()

    x = TreeNode(1)
    x.left = TreeNode(2)
    x.right = TreeNode(3)

    str = s.serialize(x)
    print str

    tree = s.deserialize(str)

    print s.serialize(tree)


if __name__ == '__main__':
    main()
