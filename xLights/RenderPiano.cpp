/***************************************************************
 * Name:      RenderPiano.cpp
 * Purpose:   Implements RGB effects
 * Author:    Matt Brown (dowdybrown@yahoo.com)
 * Created:   2012-12-23
 * Copyright: 2012 by Matt Brown
 * License:
     This file is part of xLights.

    xLights is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    xLights is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with xLights.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************/
#include <cmath>
#include "RgbEffects.h"

void RgbEffects::RenderPiano(int Keyboard)
{
    wxImage::HSVValue hsv;
    wxColour color;
    int x,y,xc,yc,n,pixel_ratio,ColorIdx;
    size_t colorcnt=GetColorCount();
    int keys,keys_mod,width,height;
    switch (Keyboard)
    {
    case 1: // smallest keyboard
    {
        width=1;
        height=3;
        break;
    }
    case 2: // medium keyboard
    {
        width=2;
        height=5;
        break;
    }
    case 3: // largest keyboard
    {
        width=3;
        height=10;
        width=6;
        height=16;
        break;
    }
    }

    ColorIdx=rand() % colorcnt;
    palette.GetColor(ColorIdx,color);
    Color2HSV(color,hsv);
    if(height>BufferHt) height=BufferHt;
    if(width>BufferWi) width=BufferWi;
    //  BufferWi ,BufferHt
    int y_start = (int) ((BufferHt/2.0) - (height/2.0));
    int y_end = y_start+height;

    int x_start=1;
    int x_end,y_end2;
    y_end2 = y_start+2*(height/3);



//    for(x=1; x<BufferWi; x++)
//        for(y=0; y<BufferHt; y++)
//        {
//            hsv.hue=((x*y)+state)/1000;
//            if(hsv.hue>1.0) hsv.hue=.5;
//            hsv.saturation=1.0;
//            hsv.value=1.0;
//
//            SetPixel(x,y,hsv);
//        }

    hsv.hue=0.0;
    hsv.saturation=1.0;
    hsv.value=1.0;

    //   Keys C,F Type 1
    //  Keys D,G,A Type 2
    //  Keys E,B Type 3
    //  Keys C#,D#,F#,G#,A# Type 4


    for (keys=1; keys<=21; keys++)
    {
        int x_start=1+((keys-1)*width);
        x_end=x_start+width-1;
        keys_mod=keys%12;

        switch (keys_mod)
        {
        case 1: // C
        case 6: // F
        {
            // hsv.hue=0.2 + (state%10)/10;
            if(hsv.hue>1.0)  hsv.hue = (state%10)/10;
            hsv.hue=.28;
            hsv.saturation=.50;
            hsv.value=.70;

            if((int)((state/100)+keys)%2 == 1)
            {
                hsv.hue=.18;
                hsv.saturation=.71;
                hsv.value=.90;
            }
            if(Keyboard==3)
            {
                for(x=x_start; x<x_end; x++)
                {
                    for (y=y_start; y<=y_end; y++)
                    {
                        SetPixel(x,y,hsv);
                    }
                }

                for (y=y_start; y<=y_end2; y++)
                {
                    SetPixel(x_end,y,hsv);
                }
            }
        }
        case 2:  // C#
        case 4:  // Eb
        case 7:  // F#
        case 9:  // Ab
        case 11: // Bb
        {
            //  hsv.hue=0.4  + (state%10)/10;
            hsv.hue=.71;
            hsv.saturation=.43;
            hsv.value=.79;
            if((int)((state/100)+keys)%2 == 0)
            {
                hsv.hue=.18;
                hsv.saturation=.71;
                hsv.value=.90;
            }

            if(width==6)
            {
                for(x=x_start-2 ; x<=x_start+1; x++)
                {
                    for (y=y_start; y<=y_end2; y++)
                    {
                        SetPixel(x,y,hsv);
                    }
                }
            }
            else
            {
                for(x=x_start-1 ; x<=x_start; x++)
                {
                    for (y=y_start; y<=y_end2; y++)
                    {
                        SetPixel(x,y,hsv);
                    }
                }
            }
        }

        case 3:  // D
        case 8:  // G
        case 10: // A
        {
            // hsv.hue=0.6  + (state%10)/10;
            hsv.hue=.48;
            hsv.saturation=.73;
            hsv.value=.74;
            if((int)((state/100)+keys)%3 == 1)
            {
                hsv.hue=.18;
                hsv.saturation=.71;
                hsv.value=.90;
            }
            if(Keyboard==3)
            {
                for (y=y_start; y<=y_end; y++)
                {
                    if(width==6)
                    {
                        SetPixel(x_start+2,y,hsv);
                        SetPixel(x_start+3,y,hsv);
                    }
                    else
                        SetPixel(x_start+1,y,hsv);
                }
                for (y=y_start; y<=y_end2; y++)
                {
                    if(width==6)
                    {
                        SetPixel(x_start,y,hsv);
                        SetPixel(x_start+1,y,hsv);
                        SetPixel(x_end-1,y,hsv);
                        SetPixel(x_end,y,hsv);
                    }
                    else
                    {
                        SetPixel(x_start,y,hsv);
                        SetPixel(x_end,y,hsv);
                    }
                }
            }
        }

        case 5:   // E
        case 0:   // B
        {
            // hsv.hue=0.2  + (state%10)/10;
            hsv.hue=.60;
            hsv.saturation=.43;
            hsv.value=.79;

            if(Keyboard==3)
            {
                if(width==6)
                {
                    for(x=x_start+2; x<=x_end; x++)
                    {
                        for (y=y_start; y<=y_end; y++)
                        {
                            SetPixel(x,y,hsv);
                        }
                    }
                    int y_end2 = y_start+height/2;
                    for (y=y_end2; y<=y_end; y++)
                    {
                        SetPixel(x_start,y,hsv);
                          SetPixel(x_start+1,y,hsv);
                    }
                }
                else
                {
                    for(x=x_start+1; x<=x_end; x++)
                    {
                        for (y=y_start; y<=y_end; y++)
                        {
                            SetPixel(x,y,hsv);
                        }
                    }
                    int y_end2 = y_start+height/2;
                    for (y=y_start; y<=y_end2; y++)
                    {
                        SetPixel(x_start,y,hsv);
                    }
                }

            }
        }

        default:
        {
            /*
            for(x=1; x<BufferWi; x++)
                for(y=0; y<BufferHt; y++)
                {
                    hsv.hue=0.0;
                    hsv.saturation=1.0;
                    hsv.value=1.0;
                    SetPixel(x,y,hsv);
                }
                */
        }
        } // switch (keys_mod)
    } //  for (keys=1; keys<=14; keys++)
}
