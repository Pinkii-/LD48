#version 120

uniform sampler2D waterTex;
uniform sampler2D collisionTex;
uniform float time;

float rand(vec2 co)
{
    float a = 12.9898;
    float b = 78.233-time;
    float c = 43758.5453+time;
    float dt= dot(co.xy ,vec2(a,b));
    float sn= mod(dt,3.14);
    return fract(sin(sn) * c);
}


vec4 t(int x, int y)
{
    float p = 1.0/200.0;
    return texture2D(waterTex, gl_TexCoord[0].st+vec2(float(x)*p, float(y)*p));
}

bool aigua(int x, int y)
{
    float p = 1.0/200.0;
    vec4 c = texture2D(waterTex, gl_TexCoord[0].st+vec2(float(x)*p, float(y)*p));
    return c.r < 0.5 && c.b > 0.5;
}

bool aire(int x, int y)
{
    if(aigua(x, y)) return false;
    float p = 1.0/200.0;
    vec4 c = texture2D(collisionTex, gl_TexCoord[0].st+vec2(float(x)*p, float(y)*p));
    return c.r > 0.5 && c.b > 0.5;
}

const int wtf[8] = int[8](
    0, 1, 2, -1, 3, -2, -3, -4
);

const int wtf2[3] = int[3](1, 1, 2);
const int wtf3[3] = int[3](2, 3, 3);

int r(int x, int y)
{
    if(!aigua(x, y))
        return 0;

    int i = 0;
    if(aire(x, y+1)) i++;
    if(aire(x-1, y)) i+=2;
    if(aire(x+1, y)) i+=4;
    i = wtf[i];

    if(i >= 0) return i;

    if(i == -3 && t(x, y).g > 0.8) return 3;
    if(i == -3 && t(x, y).g > 0.4) return 2;

    ivec2 p = ivec2(gl_TexCoord[0]*800.0);
    p += ivec2(x, y);
    float rr = rand(vec2(p));

    if(i == -4)
        return 1;
    else if(rr > 0.5)
        return wtf2[-1-i];
    else
        return wtf3[-1-i];
}

int r2(int x, int y)
{
    int res = r(x, y);
    if(res == 2 && r(x-1, y-1) == 1) return 0;
    if(res == 3 && r(x+1, y-1) == 1) return 0;
    if(res == 3 && r(x+2, y) == 2) return 0;
    return res;
}

void main(void)
{
    vec4 c = t(0, 0);

    if(aigua(0, 0))
    {
        if(r2(0,0) != 0)
            c = vec4(1, 1, 1, 1);
    }
    else if(aire(0, 0))
    {
        if(r2(0, -1) == 1)
            c = vec4(0, 0, 1, 1);
        else if(r2(1, 0) == 2)
            c = vec4(0, 0.5, 1, 1);
        else if(r2(-1, 0) == 3)
            c = vec4(0, 1, 1, 1);
    }

    gl_FragColor = c;
}
