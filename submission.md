# Project 1: Brush

Please fill this out for Brush only. The project handout can be found [here](https://cs1230.graphics/projects/raster/1).

## Output Comparison
This is how you will demonstrate the functionality of your project.

For each of the rows below, follow the instructions to record a video. Please reference the [Screen Recording Guide](
https://github.com/user-attachments/assets/48393c97-4590-4d3d-a4f6-5d331c3485ed
) for machine-specific guidance on how to do this.

Once you've recorded everything, navigate to this file in Github, click edit, and either select or drag-and-drop each of your videos into the correct location. This will upload them to GitHub (but not include them in the repo) and automatically embed them into this Markdown file by providing a link. Make sure to double-check that they all show up properly in the preview.

We're **not** looking for your video to **exactly** match the expected output (i.e. draw the exact same shape). Just make sure to follow the instructions and verify that the recording fully demonstrates the functionality of that part of your project.

### Constant Brush
**Instructions:** Draw with the constant brush.

#### Expected Output

https://github.com/BrownCSCI1230/projects_raster_template/assets/77859770/241d99b5-947a-407c-b454-410534520aad

#### Your Output

https://github.com/user-attachments/assets/a16fdae0-6af4-4262-b2ff-22da3a882357

### Linear Brush
**Instructions:** Draw with the linear brush.

#### Expected Output

https://github.com/BrownCSCI1230/projects_raster_template/assets/77859770/9706fa04-7710-441f-b292-ab010e04dec6

#### Your Output




https://github.com/user-attachments/assets/5b305872-1cc0-49d8-b594-087fc7db2f0c



### Quadratic Brush
**Instructions:** Draw with the quadratic brush.

#### Expected Output

https://github.com/BrownCSCI1230/projects_raster_template/assets/77859770/c5df5c09-bfe0-4c05-a56e-14609772d675

#### Your Output



https://github.com/user-attachments/assets/091ac70d-b25a-4f29-9744-ffe00d80b5ee





### Smudge Brush
**Instructions:** Draw some colors on the canvas and use the smudge brush to smear them together.

#### Expected Output

https://github.com/BrownCSCI1230/projects_raster_template/assets/77859770/26440b63-2d1c-43fd-95f2-55b74ad3bbed

#### Your Output



https://github.com/user-attachments/assets/7c40e200-7a3e-423e-b223-f76f875e27b3




### Smudge Brush Change in Alpha
**Instructions:** Draw some colors on the canvas. Use the smudge brush with varying alpha levels (use at least three) and demonstrate that the brush still works the same way each time.

#### Expected Output

https://github.com/BrownCSCI1230/projects_raster_template/assets/77859770/0b49c7d0-47ca-46d0-af72-48b831dfe7ea

#### Your Output


https://github.com/user-attachments/assets/2c9c3cf4-eb0a-4889-a733-f11db4f3b308




### Radius
**Instructions:** Use any brush with at least 3 different values for the radius.

#### Expected Output

https://github.com/BrownCSCI1230/projects_raster_template/assets/77859770/6f619df6-80cd-4849-8831-6a5aade2a517

#### Your Output



https://github.com/user-attachments/assets/361d51b6-ca33-426a-b535-42eee32e392b





### Color
**Instructions:** Use any brush to draw red (255, 0, 0), green (0, 255, 0), and blue (0, 0, 255).

#### Expected Output

https://github.com/BrownCSCI1230/projects_raster_template/assets/77859770/fd9578ca-e0af-433e-ac9e-b27db2ceebc9

#### Your Output


https://github.com/user-attachments/assets/c31fee63-8d1c-4975-96bf-d7eb1275543d





### Canvas Edge Behavior
**Instructions:** With any brush, click and draw on the canvas in a place where the mask intersects with the edge. Then, start drawing anywhere on the canvas and drag your mouse off of the edge.

#### Expected Output

https://github.com/BrownCSCI1230/projects_raster_template/assets/77859770/f5344248-fa5f-4c33-b6df-ff0a45011c7a

#### Your Output


https://github.com/user-attachments/assets/be8e1a4a-1d8e-476b-8010-4a42fa68a152





### Alpha
**Instructions:** With the constant brush, draw a single dot of red (255, 0, 0) with an alpha of 255. Then, draw over it with a single dot of blue (0, 0, 255) with an alpha of 100. You should get a purpleish color.

#### Expected Output

https://github.com/BrownCSCI1230/projects_raster_template/assets/77859770/b13d312d-d6d4-4375-aeaa-96174065443b

#### Your Output


https://github.com/user-attachments/assets/15beb600-9f5d-471f-8f1d-3d728b94ee06




### Alpha of Zero
**Instructions:** Choose any brush and demonstrate that it will not draw if the alpha value is zero.

#### Expected Output

https://github.com/BrownCSCI1230/projects_raster_template/assets/77859770/8e48777e-8196-401e-9af6-871abe712146

#### Your Output



https://github.com/user-attachments/assets/7341d79a-12d1-488a-9b63-5ab4ebf4e1e7




## Design Choices

I decided to create a separate brush file to house the bulk of the brush logic. Thought this was a good design choice because this class housed all the functions related to
brush, such as the drawing and smudging, as well as the type updates. Due to the creation
of this class, there was little change applied to the actual canvas2d file, only have the mouse events
updated to detect whether it is the right time for the brush to be applied to the canvas. Another choice done 
within the canvas2d file is within settingsChanged. Instead of updating the mask every single time a setting is changed,
I used variables to detect whether only radius or brushType were changed. 

## Collaboration/References

AI was used to understand C++ syntax and search up definitions as this is my first
time ever coding in C++.

## Known Bugs

N/A

## Extra Credit

N/A

