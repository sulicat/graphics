from PIL import Image
import numpy as np
import scipy.misc
import matplotlib
import matplotlib.pyplot
from numpy import *

#width = 1280
#height = 720
#channels = 3

width = 500
height = 500
channels = 3


output = Image.new("RGB", (width, height))
data = np.zeros( (height, width, channels), dtype=np.uint8 )
xx, yy = np.mgrid[ :height, :width ]


def closestPointOnLine(a, b, p):
    ap = np.subtract(p,a)
    ab = np.subtract(b,a)
    result = a + np.dot(ap,ab)/np.dot(ab,ab) * ab
    return result

class Camera:
    def __init__(self, _pos = (0,0,0)):
        self.pos = _pos
        self.min_dist = 10
        self.max_dist = 300
        self.view_dist = self.max_dist - self.min_dist

class Ray:
    def __init__( self, _pos = (0.0,0.0,0.0), _tip = (0.0,0.0,1.0) ):
        self.pos = _pos
        self.tip = _tip
        self.mult = tuple(np.subtract(self.tip, self.pos))

    def len( self ):
        a = np.array(self.pos)
        b = np.array(self.tip)
        return np.linalg.norm(a-b)


class Sphere:
    def __init__(self, _pos = (0.0, 0.0 ,2.0 ), _rad = 250.0, color = (255, 0, 0) ):
        self.pos = _pos
        self.r = _rad
        self.color = color

    def intersect(self, ray):
        # a ray from the center of the ray and center of the sphere
        dist_r = Ray( ray.pos, self.pos )
        dist = dist_r.len()
        # will tell us if sphere is behind the ray or not
        dist_ray_dot = np.dot( ray.tip, dist_r.tip )
        if( dist_ray_dot <= 0 ):
            return False, None, None


        point_along_ray = closestPointOnLine( ray.pos, ray.tip, self.pos )
        projection_ray = Ray( self.pos, (point_along_ray[0], point_along_ray[1], point_along_ray[2]) )
        new_projection_ray = Ray( ray.pos, (point_along_ray[0], point_along_ray[1], point_along_ray[2]) )

        # if the ray is intersecting the sphere
        if( projection_ray.len() < self.r ):
            dist_to_move_along_ray = sqrt((self.r**2) - (projection_ray.len()**2))
            #print( str(dist_to_move_along_ray) + " " + str(new_projection_ray.len()) + " " +  str(dist_to_move_along_ray/new_projection_ray.len()))

            ratio = dist_to_move_along_ray / new_projection_ray.len()
            pnt = ( new_projection_ray.pos[0] + new_projection_ray.tip[0]*ratio,
                    new_projection_ray.pos[1] + new_projection_ray.tip[1]*ratio,
                    new_projection_ray.pos[2] + new_projection_ray.tip[2]*ratio )

            distance_traveled = new_projection_ray.len() - dist_to_move_along_ray

            #pnt = (0,0,0)
            return True, pnt, distance_traveled



        return False, None, None




camera = Camera()
print(camera.pos)



s1 = Sphere( ( 0.0, 0.0, 300.0 ) )
s2 = Sphere( ( 100.0, 100.0, 200.0 ), 50, color = (0,255,0) )
#s1 = Sphere( (0,0, -100) )

spheres = ( s1, s2 )


r = Ray( (0,0,0), (0,10,0) )
p = (2,10,0)
point_along_ray = closestPointOnLine( r.pos, r.tip, p )
#print( point_along_ray )



i = 0
total = data.shape[0]*data.shape[1]
# for every pixel
for y in range( data.shape[0] ):
    for x in range( data.shape[1]):
        # create a ray from the camera position to the pixel

        for s in spheres:
            ray = Ray(camera.pos, (float(x-(width/2)), float(y-(height/2)), 100 ))
            #print(str(ray.pos) + " " + str(ray.tip) + " " + str(ray.mult))
            intersect, pnt, distance = s.intersect(ray)

            if intersect:
                data[y][x][0] = (distance / camera.view_dist) * s.color[0]
                data[y][x][1] = (distance / camera.view_dist) * s.color[1]
                data[y][x][2] = (distance / camera.view_dist) * s.color[2]
            else:
                data[y][x][0] += 0
                data[y][x][1] += 0
                data[y][x][2] += 0


        print(int((i/total) * 100))
        i+=1




matplotlib.pyplot.imshow(data)
matplotlib.pyplot.show()
output.save("raytrace.png")


