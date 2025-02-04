# FDF
FDF (Fil de Fer) is the first graphic project at École 42. Using a graphic library such as MinilibX or Codam, the goal is to display a wireframe 3D view based on a 2D map/matrix.

## Process
To accomplish this, the program follows these steps:

### 1. Validate Map
The first step is to check if the map has a .fdf extension, exists, and is not empty.

### 2. Initiate Variables
It is necessary to create some structures to store information required for rendering the map in 3D later.
- **MAP**: The `map` structure holds map information, such as its width, height, maximum and minimum altitude (z-axis) and the **matrix**, where I save x, y, z and color value of each map point are stored.
- **MLX**: Initializes `mlx`, `image`, and `window` using MLX42 library functions such as `mlx_init`, `mlx_new_image`, and `mlx_image_to_window`.
- **CAM**: The `cam` structure holds important information for rendering the map, such as `tile` and `tile_z` sizes (distance between points) and `offset_x` and `offset_y` values to center the image.

### 3. Render Map
To render the map, the program loops through matrix points, draws lines by calculating each pixel between points, and renders each pixel using `mlx_put_pixel` function from the library. The program follows these steps:
- **Loop Matrix**: While looping, the program sends the current point as `start` and next point on the x and y axis as `end` to the `render_line` function.
- **Calculate Projection**: For each `start` and `end` point with x, y and z value, the program projects them onto 2D coordinates to represent a 3D model on a 2D screen.
- **Draw Line**: After calculating the projection of `start` and `end` points, the `draw_line` function is called to calculate each pixel of the line from `start` to `end` using Bresenham's line algorithm. As it calculates, it renders the pixel on the screen.

### 4. Free Variables
Finally, all allocated memory is freed, including variables allocated using the library, such as `mlx`, which is terminated using the `mlx_terminate` function.

## Color
I added different colors depending on the point height, with a gradient between them to make it easier to visualize the 3D model with a smooth transition between colors.

## Bonus
In the bonus part I added:
- Rotation of the model on x, y and z axes
    - To rotate on x-axis: A/D keys
    - To rotate on y-axis: W/S keys
    - To rotate on z-axis: Q/E keys
- Translation of the model: arrows keys
- 5 extra projections
    - Isometric projection: key 0
    - Parallel projection: key 1
    - Top projection: key 2
    - Front projection: key 3
    - Right projection: key 4
    - Left projection: key 5
- Zoom in and out: +/- keys
- Height increase and decrease: I/O keys
