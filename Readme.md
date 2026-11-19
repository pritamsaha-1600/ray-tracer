# Coordinate Systems

1. World coordinate: 3 dim floating-point type, unbounded. Origin represents the middle of the world.
Represents the virtual world. The camera, objects, viewport/scren and image are specified in terms of world coordinates. 

2. Viewport coordinate: 2 dim floating-point type, bounded by the viewport dimensions. Origin is at the geometric centre of the viewport. Represents points on the viewport.

3. Image coordinate: 2 dim integral type, bounded by the viewport dimensions. Origin is at the top-left corner of the image. y-axis increases downwards. Represents pixels of the image.

# Decisions

- Chose to keep world coordinate axes such that increasing z is out of the screen, towards the viewer. The other alternative of increasing z axis up the screen makes the depth coordinate y coordinate, which is weird.

- Chose to decouple image dimensions from render window (i.e. viewport), as changing image dimensions should impact resolution of the image, and not how much of the world is visible. Change resolution by changing the image dimension, and how much of the world is visible with viewport dimensions.