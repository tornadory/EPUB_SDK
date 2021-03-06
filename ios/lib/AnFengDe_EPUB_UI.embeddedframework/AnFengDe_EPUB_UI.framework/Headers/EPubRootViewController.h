/*!
 * \author qqwang
 * \brief The epub root view definition 
 * \file EPubRootViewController.h
 * \version 1.0 
 * \date 2012-07-06
 * \copyright (c) 2012年 com.anfengde. All rights reserved.
 * */

#import <UIKit/UIKit.h>
#import "EPubBook.h"
#import "GADBannerViewDelegate.h"

@class GADBannerView, GADRequest;
@class EPubContentsViewController;

@interface EPubRootViewController : UIViewController <UIWebViewDelegate, UIGestureRecognizerDelegate,GADBannerViewDelegate>{
    GADBannerView *adBanner_;
    EPubBook *epubBook;
    int currentPageNum;
    int currentFontSize;
    int totalPages;
    int pIndex;
    int sIndex;
    int cIndex;
    NSString *urlPrefix;
    NSString *clickBk;

@private
    UIWebView *afd_webView;
}

/** The current reading book */
@property (nonatomic, retain) EPubBook *epubBook;
@property (nonatomic, retain) GADBannerView *adBanner;
@property (nonatomic, readwrite) int currentPageNum;
@property (nonatomic, readwrite) int currentFontSize;
@property (nonatomic, readwrite) int totalPages;
@property (nonatomic, readwrite) int pIndex;
@property (nonatomic, readwrite) int sIndex;
@property (nonatomic, readwrite) int cIndex;
@property (nonatomic, retain) NSString *urlPrefix;
@property (nonatomic, retain) NSString *clickBk;


- (GADRequest *)createRequest;

/**
  Initialize a new nib file
  @param nibNameOrNil is the name of nib
  @param nibBundleOrNil is the name of bundle
  @param bookPath is the full path of current book
  @returns a newly initialize object
 */
- (id) initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil epubBookPath:(NSString *)bookPath;
/** 
 Open chapter 
 @param chapterPath is the chapter path
 */
- (void)openChapter:(NSString*)chapterPath;
/** Inject js to html when open a link */
- (NSString*)openURL;
/** Save the reading status */
- (void)saveReadStatus;
/** Read the reading status */
- (void)readStatusData;
/** The path of configuration file */
- (NSString *) innerConfigurationFilePath;
/** Read the configuration file */
- (void)readInnerConfigurationFromFile;
/** Save the configuration */
- (void)saveInnerConfigurationToFile;
/** Write js and css to device */
- (void) writeJS:(NSString*)fileName type:(NSString*)type folder:(NSString*)folder;
/** Return html content with js and css */
- (NSString*) urlContent:(NSString*)htmlContent;
/** show error message */
- (void) showErrorCode:(NSString*)errorMes;
- (void)resizePage;
@end
