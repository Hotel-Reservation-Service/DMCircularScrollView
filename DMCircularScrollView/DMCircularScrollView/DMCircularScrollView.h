//
//  DMCircularScrollView.h
//  DMCircularScrollView
//
//  Created by Daniele Margutti on 8/16/12.
//  Copyright (c) 2012 Daniele Margutti. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef UIView *(^DMCircularScrollViewDataSource)(NSUInteger pageIndex);
typedef void(^DMCircularScrollViewPageChanged)(NSUInteger currentPageIndex,NSUInteger previousPageIndex);

@interface DMCircularScrollView : UIView

@property (nonatomic,assign)    CGFloat                             pageWidth;              // Single page width (picker is centered)
@property (nonatomic,readonly)    NSUInteger                          currentPageIndex;       // Current page index (DMCircularScrollView uses tag property of UIVIew, so don't touch it.)
@property (nonatomic,assign)    BOOL                                allowTapToChangePage;   // Allows single tap on scroll view side to change next/prev
@property (nonatomic,assign)    BOOL                                displayBorder;          // Display a green border around the scrollView
@property (copy)                DMCircularScrollViewPageChanged     handlePageChange;       // Block to catch page change event
@property (nonatomic, assign)   id                                  scrollViewDelegate;     // Delegate for passing through UIScrollView delegate calls

@property(nonatomic, readonly) NSUInteger previousPageIndex;
@property(nonatomic, readonly) NSUInteger totalPages;

- (void)setPageCount:(NSUInteger) pageCount withDataSource:(DMCircularScrollViewDataSource) dataSource;
- (void)reloadData;

- (IBAction)goNext:(id)sender;
- (IBAction)goBack:(id)sender;

- (void)goNextAnimated:(BOOL)animated;
- (void)goBackAnimated:(BOOL)animated;

@end