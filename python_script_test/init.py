from vetche_api import *

def start():

    vec2 = Vec2(10, 10)

    obj = Object("Test")
    obj.print()

    node = Node("Child", vec2)
    node.print()

    node.position.x = 11

    print(node.name, node.position.x)