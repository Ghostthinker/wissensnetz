<?php

use adminapi\services\UserService;
use Wissensnetz\User\DrupalUser;

class SaltoUserCest {

  public function _before(UnitTester $I) {
  }

  public function _after(UnitTester $I) {
  }


  public function testUpdateServiceUpdateProfile(UnitTester $I) {

    $USER = $I->haveUser();

    $profile = [
      'firstName' => 'Jane',
      'lastName' => 'Burg',
      'profile' => [
        'email' => 'jane.burg@example.com'
        ]
    ];

    $drupalUser = DrupalUser::make($USER->uid);
    $userService = new UserService($drupalUser);

    $I->completedSetup();

    $I->expect('that i can update the user profile');

    $userService->updateUserProfile($profile);
    $drupalUser->reload();

    $I->assertEquals($profile['firstName'], $drupalUser->getFirstName());
    $I->assertEquals($profile['lastName'], $drupalUser->getLastName());
    $I->assertEquals($profile['profile']['email'], $drupalUser->getProfileMail());

    $I->expect('that the values keep the same if they are not in the request');

    $userService->updateUserProfile([]);
    $drupalUser->reload();

    $I->assertEquals($profile['firstName'], $drupalUser->getFirstName());
    $I->assertEquals($profile['lastName'], $drupalUser->getLastName());
    $I->assertEquals($profile['profile']['email'], $drupalUser->getProfileMail());

  }

  public function testUpdateServiceUpdateProfilePicture(UnitTester $I) {

    $I->wantTo('that i can update the profile picture');



    $USER = $I->haveUser();

    $drupalUser = DrupalUser::make($USER->uid);

    $I->completedSetup();

    $I->expect('a new user have a default image');

    $image = $drupalUser->getProfileImage();
    $I->assertEmpty($image);

    $userService = new UserService($drupalUser);

    $I->expect('that the image is now updated');
    $userService->updateUserPicture('https://fastly.picsum.photos/id/281/200/300.jpg?hmac=KCN8F5QTgxHdeQxLpZ5BOuUEVQEp8jAedlLSRERW7CY');
    $drupalUser->reload();
    $imageNew = $drupalUser->getProfileImage();

    $I->assertNotEmpty($imageNew);

    $I->expect('that i can update an existing image');

    $userService->updateUserPicture('https://fastly.picsum.photos/id/904/200/300.jpg?hmac=t7FNdMa1LwaLz0quPrFzXgqADg_jjQ4t7PuZeig7mY8');
    $drupalUser->reload();
    $imageUpdated = $drupalUser->getProfileImage();

    $I->assertNotEquals($imageNew['filesize'], $imageUpdated['filesize']);

  }

  public function testUpdateAccountMail(UnitTester $I){
    $I->wantTo('that i can update the account mail');

    $USER = $I->haveUser();

    $drupalUser = DrupalUser::make($USER->uid);
    $userService = new UserService($drupalUser);

    $I->completedSetup();

    $mail = 'jane.burg@example.com';
    $data = [
      'email' => $mail
    ];
    $userService->updateUserAccount($data);

    $drupalUser->reload();

    $I->assertEquals($mail, $drupalUser->getLoginMail());
  }

  public function testUpdateAccountMailDouble(UnitTester $I){
    $I->wantTo('that i cant update the account mail');

    $mail = 'jane.burg@example.com';
    $USER = $I->haveUser();
    $USER2 = $I->haveUser(['mail' => $mail]);

    $drupalUser = DrupalUser::make($USER->uid);
    $userService = new UserService($drupalUser);

    $I->completedSetup();


    $data = [
      'email' => $mail
    ];


    $drupalUser->reload();
    $I->expectThrowable(\Wissensnetz\User\Exception\DrupalUserDoubleMailException::class, function () use ($userService, $data){
      $userService->updateUserAccount($data);
    });

    $I->assertNotEquals($mail, $drupalUser->getLoginMail());
  }

}
