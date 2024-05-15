#include "./SBDL.h"

using namespace std;

    Font*   font  ;
	Texture play  ;
	SDL_Rect playRect ;

	Texture exit1  ;
	SDL_Rect exitRect ;

	Texture pouse  ;
	SDL_Rect pouseRect;

	Texture restart ;
	SDL_Rect restartRect ;

	Texture resume ;
	SDL_Rect resumeRect ;

	Texture menu ;
	SDL_Rect menuRect ;

	SDL_Rect arrow1Rect ;
	SDL_Rect arrow2Rect ;

	SDL_Rect lose   ;
	SDL_Rect choose ;

	Texture  lose1   ;
	Texture  choose1 ;
	
	Texture arrow1 ;
	Texture arrow2 ;
    Texture arrow  ;
	Texture block  ;
	Texture gem    ;
	Texture apple  ;
	Font*   font1  ;
	Music*  music  ;

	int deg ;
	int h   ;
	int y   ;
	int state   ;
	int speedlr ;
	int score   ;
	int speed   ;
	int framecount ;
	int x ;
	int result ;
	
	int x1 , x2 , x3 , x4 , x5 , x6 , x7 , x8 , x9 , x10 ;

	int y1 , y2 , y3 , y4 , y5 , y6 , y7 , y8 , y9 , y10 ;

	SDL_Rect rectArrow ;

	SDL_Rect gemRect   ;

	SDL_Rect appleRect ;

	SDL_Rect block1 ;
	SDL_Rect block2 ;
	SDL_Rect block3 ;
	SDL_Rect block4 ;
	SDL_Rect block5 ;
	SDL_Rect block6 ;
	SDL_Rect block7 ;
	SDL_Rect block8 ;
	SDL_Rect block9 ;
	SDL_Rect block10;

	SDL_Rect block11 ;
	SDL_Rect block12 ;
	SDL_Rect block13 ;
	SDL_Rect block14 ;
	SDL_Rect block15 ;
	SDL_Rect block16 ;
	SDL_Rect block17 ;
	SDL_Rect block18 ;
	SDL_Rect block19 ;
	SDL_Rect block20 ;

void showMenu()
{
	if( x == 0 )
	{
		choose1 = SBDL::createFontTexture(font , "Choose One" , 0 , 0 , 0) ;
		choose = {20,20,100,30} ;
		SBDL::showTexture(choose1 , choose) ;

		arrow1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/arrow.png") ;
	    arrow2 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/arrow1.png") ;
		arrow1Rect = {100,100,20,20} ;
		arrow2Rect = {150,100,20,20} ;

		SBDL::showTexture(arrow1 , arrow1Rect) ;
		SBDL::showTexture(arrow2 , arrow2Rect) ;

		if(SBDL::mouseInRect(arrow1Rect))
		{
		    arrow = arrow1 ;
			x = 1 ;
		}

		else if(SBDL::mouseInRect(arrow2Rect))
		{
			arrow = arrow2 ;
			x = 1 ;
		}
		
	}
	if(state == 0)
	{
		font  = SBDL::loadFont("C:/Users/mokht/Desktop/assets1/CenturyGothic.ttf",30) ;
	    play  = SBDL::createFontTexture(font , "PLAY" , 0 , 0 , 0) ;
	    playRect = {200,300,100,20} ;

	    exit1  = SBDL::createFontTexture(font , "EXIT" , 0 , 0 , 0) ;
	    exitRect = {200,320,100,20} ;

	if(SBDL::mouseInRect(playRect))
	{
	state = 1 ;
	score = 0 ;
	speed = 1 ;
	rectArrow = {250,400,25,25} ;
	exitRect = {0,0,0,0} ;
	playRect = {0,0,0,0} ;
	}

	else if (SBDL::mouseInRect(exitRect))
	{
	state = 2 ;
	exitRect = {0,0,0,0} ;
	playRect = {0,0,0,0} ;
	}

	else 
	{
		if(state == 0)
		{
	    SBDL::showTexture( play , playRect ) ;
        SBDL::showTexture( exit1, exitRect ) ;
		}
	}
	}

	else if(state == 5)
	{
	restart = SBDL::createFontTexture(font , "RESTART" , 0 , 0 , 0) ;
	restartRect = {300,300,100,20} ;

	resume = SBDL::createFontTexture(font , "RESUME" , 0 , 0 , 0) ;
	resumeRect = {300,320,100,20} ;

		if(SBDL::mouseInRect(restartRect))
	    {
		state = 1 ;
		score = 0 ;
		speed = 1 ;
		rectArrow = {250,400,25,25} ;
		resumeRect = {0,0,0,0} ;
		restartRect = {0,0,0,0} ;
	    }

	    else if(SBDL::mouseInRect(resumeRect))
		{
	    state = 1 ;
		resumeRect = {0,0,0,0} ;
		restartRect = {0,0,0,0} ;
		}

	    else if(state == 5) 
	    {
		SBDL::showTexture(resume , resumeRect) ;
	    SBDL::showTexture(restart, restartRect);	
	    }
	}
		else if(state == 10)
		{
			lose1 = SBDL::createFontTexture(font,"You Lose ! Your Score = " + to_string(score) , 0 , 0 , 0) ; 
			lose = {100,100,200,30} ;
			SBDL::showTexture(lose1 , lose ) ;

			restartRect = {200,200,100,20} ;
			SBDL::showTexture(restart , restartRect ) ;
			menuRect = {200,220,100,20} ;
			SBDL::showTexture(menu , menuRect) ;
			exitRect = {200,240,100,20} ;
			SBDL::showTexture(exit1 , exitRect ) ;

			if(SBDL::mouseInRect(restartRect))
			{
			score = 0 ;
			state = 1 ;
			speed = 1 ;
			rectArrow = {250,400,25,25} ;

			restartRect = {0,0,0,0} ;
			menuRect = {0,0,0,0} ;
			exitRect = {0,0,0,0} ;
			}

			else if(SBDL::mouseInRect(menuRect))
			{
			state = 0 ;
			score = 0 ;
			showMenu() ;
			restartRect = {0,0,0,0} ;
			menuRect = {0,0,0,0} ;
			exitRect = {0,0,0,0} ;
			}

			else if(SBDL::mouseInRect(exitRect))
			{
			state = 2 ;
			restartRect = {0,0,0,0} ;
			menuRect = {0,0,0,0} ;
			exitRect = {0,0,0,0} ;
			}

			else if(state == 10)
			{
			SBDL::showTexture(restart , restartRect ) ;		
			SBDL::showTexture(menu , menuRect) ;
			SBDL::showTexture(exit1 , exitRect ) ;
			}


		}
}

int main(int argc, char *argv[])
{
	
	const int window_width = 500;
	const int window_height = 500;
	SBDL::InitEngine("SBDL Test", window_width, window_height);

	const int FPS = 60; //frame per second
	const int delay = 1000 / FPS; //delay we need at each frame

	arrow1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/arrow.png") ;
	arrow2 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/arrow1.png") ;
    music  = SBDL::loadMusic("C:/Users/mokht/Desktop/assets1/chilled_v1.mp3") ;
	SBDL::playMusic(music , -1 ) ;

	    font  = SBDL::loadFont("C:/Users/mokht/Desktop/assets1/CenturyGothic.ttf",30) ;
	    play  = SBDL::createFontTexture(font , "PLAY" , 0 , 0 , 0) ;
	    playRect = {200,300,100,20} ;

	    exit1  = SBDL::createFontTexture(font , "EXIT" , 0 , 0 , 0) ;
	    exitRect = {200,320,100,20} ;

		restart = SBDL::createFontTexture(font , "RESTART" , 0 , 0 , 0) ;
	    restartRect = {300,300,100,20} ;

	    resume = SBDL::createFontTexture(font , "RESUME" , 0 , 0 , 0) ;
	    resumeRect = {300,320,100,20} ;


	pouse  = SBDL::createFontTexture(font , "PRESS C TO POUSE", 0 , 0 , 0) ;
	pouseRect= {250,0,150,30} ;

	menu   = SBDL::createFontTexture(font , "MENU" , 0 , 0 , 0) ;

	block  = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/wall_7.png") ;
	gem    = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/gem.png") ;
	apple  = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/apple.png") ;
	font1  = SBDL::loadFont("C:/Users/mokht/Desktop/assets1/CenturyGothic.ttf",20) ;
	
	deg = 0 ;
	h = 30 ;
	y = 20 ;
	speedlr = 5 ;
	score = 0;
	speed = 1 ;
	framecount = 0 ;
	
	x1 = rand()%150 , x2 = rand()%150 , x3 = rand()%150 , x4 = rand()%150 , x5 = rand()%150 , x6 = rand()%150 , x7 = rand()%150 , x8 = rand()%150 , x9 = rand()%150 , x10 = rand()%150 ;

	y1 =300 + rand()%150 , y2 =300 + rand()%150 , y3 =300 + rand()%150 , y4 =300 + rand()%150 , y5 =300 + rand()%150 , y6 =300 + rand()%150 , y7 =300 + rand()%150 , y8 =300 + rand()%150 , y9 =300 + rand()%150 , y10 =300 + rand()%150 ;

	rectArrow = {250,400,25,25} ;

    gemRect   = {170,100,20,20} ;

	appleRect = {180,200,15,15} ;

	block1  = {0,0,x1,100}     ;
    block2  = {0,100,x2,100}   ;
	block3  = {0,200,x3,100}   ;
	block4  = {0,300,x4,100}   ;
	block5  = {0,400,x5,100}   ;
	block6  = {0,-100,x6,100}  ;
	block7  = {0,-200,x7,100}  ;
	block8  = {0,-300,x8,100}  ;
	block9  = {0,-400,x9,100}  ;
	block10 = {0,-500,x10,100} ;

	block11 = {y1,0,200,100}     ;
	block12 = {y2,100,200,100}   ;
	block13 = {y3,200,200,100}   ;
	block14 = {y4,300,200,100}   ;
	block15 = {y5,400,200,100}   ;
	block16 = {y6,-100,200,100}  ;
	block17 = {y7,-200,200,100}  ;
	block18 = {y8,-300,200,100}  ;
	block19 = {y9,-400,200,100}  ;
	block20 = {y10,-500,200,100} ;
	
	
	while (SBDL::isRunning()) {
		int startTime = SBDL::getTime();
		
		SBDL::updateEvents();
		SBDL::clearRenderScreen();

		//Game logic code
		
		showMenu() ;
		

		if (state == 2) 
		break ;

		if (state == 1) {
		if (SBDL::keyHeld(SDL_SCANCODE_SPACE))
		{
			if (deg>-45)
			deg-=5 ;
			rectArrow.x-=speedlr ;
		}
		else {
			deg=45 ;
			rectArrow.x+=speedlr ;
		}

		SBDL::showTexture(arrow , deg , rectArrow) ;

		char ch =  score + '0';

		string s = "Score= " + to_string(score);
			
	    Texture score1= SBDL::createFontTexture(font1 , s ,0,0,0) ;

		framecount++ ;

		if(framecount==600)
		{
			framecount = 0 ;
			if(speed<10)
			{
			speed++ ;
			}
		}

		SBDL::showTexture(block , block1 ) ;
		SBDL::showTexture(block , block2 ) ;
		SBDL::showTexture(block , block3 ) ;
		SBDL::showTexture(block , block4 ) ;
		SBDL::showTexture(block , block5 ) ;
		SBDL::showTexture(block , block6 ) ;
		SBDL::showTexture(block , block7 ) ;
		SBDL::showTexture(block , block8 ) ;
	    SBDL::showTexture(block , block9 ) ;
		SBDL::showTexture(block , block10) ;

		SBDL::showTexture(block , block11) ;
		SBDL::showTexture(block , block12) ;
		SBDL::showTexture(block , block13) ;
		SBDL::showTexture(block , block14) ;
		SBDL::showTexture(block , block15) ;
		SBDL::showTexture(block , block16) ;
		SBDL::showTexture(block , block17) ;
		SBDL::showTexture(block , block18) ;
		SBDL::showTexture(block , block19) ;
		SBDL::showTexture(block , block20) ;

		block1.y+=speed ;
	    block2.y+=speed ;
	    block3.y+=speed ;
	    block4.y+=speed ;
	    block5.y+=speed ;
	    block6.y+=speed ;
	    block7.y+=speed ;
	    block8.y+=speed ;
	    block9.y+=speed ;
	    block10.y+=speed ;

		if (block1.y>= 500 )
		{
		block1.y -= 1000 ;
	    block2.y -= 1000 ;
	    block3.y -= 1000 ;
	    block4.y -= 1000 ;
	    block5.y -= 1000 ;
		}

		if (block10.y >= 500)
		{
		block6.y -= 1000 ;
	    block7.y -= 1000 ;
	    block8.y -= 1000 ;
	    block9.y -= 1000 ;
	    block10.y -= 1000 ;
		}

		block11.y+=speed ;
	    block12.y+=speed ;
	    block13.y+=speed ;
	    block14.y+=speed ;
	    block15.y+=speed ;
	    block16.y+=speed ;
	    block17.y+=speed ;
	    block18.y+=speed ;
	    block19.y+=speed ;
	    block20.y+=speed ;

		if (block11.y >=500 )
		{
		block11.y -= 1000 ;
	    block12.y -= 1000 ;
	    block13.y -= 1000 ;
	    block14.y -= 1000 ;
	    block15.y -= 1000 ;
		}

		if (block20.y >= 500)
		{
		block16.y -= 1000 ;
	    block17.y -= 1000 ;
	    block18.y -= 1000 ;
	    block19.y -= 1000 ;
	    block20.y -= 1000 ;
		}

		SBDL::showTexture( gem , gemRect ) ;

		if(SBDL::hasIntersectionRect( rectArrow , gemRect ) ) 
		{
			gemRect.y -=1000 ; 
			score += 10 ;
			gemRect.y+=speed ;
		}

		else
		{
		
		if(gemRect.y >= 500)
		{
			
			gemRect.x += h ;
			gemRect.y -= 1000 ;
			h = h *-1 ;
			
			if (gemRect.x >= 280)
			{
				gemRect.x = 185 ;
			}
			
		}

		gemRect.y+=speed ;

		}

		SBDL::showTexture(apple , appleRect ) ;

		if(SBDL::hasIntersectionRect(rectArrow , appleRect)) 
		{
			appleRect.y -=600 ; 
			score ++ ;
			appleRect.y+=speed ;
		}

		else
		{

		if(appleRect.y >= 500)
		{
			
			appleRect.x += h ;
			appleRect.y -= 600 ;
			h = h *-1 ;
			
			if (appleRect.x >= 275)
			{
				appleRect.x = 170 ;
			}
			
		}

		appleRect.y+=speed ;

		}

		SBDL::showTexture(score1 , 0 , 0) ;

		SBDL::showTexture(pouse , pouseRect ) ;

		if(SBDL::keyPressed(SDL_SCANCODE_C))
		{
		state  = 5 ;	
		showMenu() ;
		}

		if(SBDL::hasIntersectionRect(rectArrow , block1)||SBDL::hasIntersectionRect(rectArrow , block2)||SBDL::hasIntersectionRect(rectArrow , block3)||SBDL::hasIntersectionRect(rectArrow , block4)||SBDL::hasIntersectionRect (rectArrow , block5)||SBDL::hasIntersectionRect(rectArrow , block6)||SBDL::hasIntersectionRect(rectArrow , block7)||SBDL::hasIntersectionRect(rectArrow , block8)||SBDL::hasIntersectionRect(rectArrow , block9)||SBDL::hasIntersectionRect(rectArrow , block10)||SBDL::hasIntersectionRect(rectArrow , block11)||SBDL::hasIntersectionRect(rectArrow , block12)||SBDL::hasIntersectionRect(rectArrow , block13)||SBDL::hasIntersectionRect(rectArrow , block14)||SBDL::hasIntersectionRect(rectArrow , block15)||SBDL::hasIntersectionRect(rectArrow , block16)||SBDL::hasIntersectionRect(rectArrow , block17)||SBDL::hasIntersectionRect(rectArrow , block18)||SBDL::hasIntersectionRect(rectArrow , block19)||SBDL::hasIntersectionRect(rectArrow , block20)||rectArrow.x>500)
		{
			state = 10 ;
			showMenu() ;
		}

		}

		SBDL::updateRenderScreen();
		
		int elapsedTime = SBDL::getTime() - startTime;
		if (elapsedTime < delay)
			SBDL::delay(delay - elapsedTime);

	} 
}
